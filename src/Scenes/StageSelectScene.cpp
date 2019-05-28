#include "StageSelectScene.hpp"
#include "PlayScene.hpp"
#include "AudioHelper.hpp"
#include "Slider.hpp"
#include "LOG.hpp"

void StageSelectScene::Initialize() {
	int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
	int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    AddNewObject( new Engine::Label( "Levels", "pirulen.ttf", 72, halfW , 200 , 255, 0, 0, 255, 0.5, 0.5 ) );
    ConstructStageList();
    // Not a safe way, however we only free while change scene, so it's fine.
    bgmInstance = al_create_sample_instance(Engine::Resources::GetInstance().GetSample("select.ogg").get());
    al_set_sample_instance_playmode(bgmInstance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(bgmInstance, al_get_default_mixer());
    al_play_sample_instance(bgmInstance);
}
void StageSelectScene::PlayOnClick(int stage) {
    PlayScene* scene = dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetScene("play"));
    scene->MapId = stage;
    Engine::GameEngine::GetInstance().ChangeScene("play");
}

void StageSelectScene::ConstructStageList() {
    int i, j, stage = 1;
    for(j = 0 ; j< 3 ; j++){
        for(i = 0 ;i < 10 ; i++ ){
            Engine::ImageButton* btn;
            btn = new Engine::ImageButton( "stage-select/dirt.png", "stage-select/floor.png", 80 + 150 * i, 350 + 150 * j, 100, 100 );
            btn->SetOnClickCallback( std::bind( &StageSelectScene::PlayOnClick, this,  stage) );
            AddNewControlObject( btn );
            AddNewObject( new Engine::Label( std::to_string(stage), "pirulen.ttf", 48, 130 + 150 * i, 400 + 150 * j, 255, 0, 0, 255, 0.5, 0.5 ) );
            stage++;
        }
    }

}