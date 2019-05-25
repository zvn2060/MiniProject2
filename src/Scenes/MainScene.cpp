#include "Scenes/MainScene.hpp"
#include "Scenes/SettingScene.hpp"
#include "Scenes/PlayScene.hpp"
#include "AudioHelper.hpp"
#include "Slider.hpp"
#include "LOG.hpp"

void MainScene::Initialize() {
	int w = Engine::GameEngine::GetInstance().GetScreenSize().x;	//set window width
	int h = Engine::GameEngine::GetInstance().GetScreenSize().y;	//set window height
	int halfW = w / 2;
	int halfH = h / 2;
	Engine::ImageButton* btn;
	btn = new Engine::ImageButton( "UI/setting.png", "UI/setting_CL.png", 0, 0, 100, 100 );
	btn->SetOnClickCallback( std::bind( &MainScene::SettingOnClick, this, 1 ) );
	AddNewControlObject( btn );
	btn = new Engine::ImageButton( "UI/return.png", "UI/return_CL.png", w - 100, 0, 100, 100 );
	btn->SetOnClickCallback( std::bind( &MainScene::BackOnclick, this, 1 ) );
	AddNewControlObject(btn);
	btn = new Engine::ImageButton( "stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH + 200, 400,
								   100 );
	AddNewObject( new Engine::Label( "Play", "pirulen.ttf", 48, halfW, halfH + 200, 0, 0, 0, 255, 0.5, 0.5 ) );
	btn->SetOnClickCallback( std::bind( &MainScene::PlayOnclick, this, 1 ) );
	AddNewControlObject( btn );
	bgmInstance = al_create_sample_instance(Engine::Resources::GetInstance().GetSample("select.ogg").get());
	al_set_sample_instance_playmode(bgmInstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(bgmInstance, al_get_default_mixer());
	al_play_sample_instance(bgmInstance);
}

void MainScene::SettingOnClick( int stage ){
	SettingScene * scene = dynamic_cast<SettingScene *>(Engine::GameEngine::GetInstance().GetScene( "setting" ));
	Engine::GameEngine::GetInstance().ChangeScene( "setting" );
}

void MainScene::BackOnclick( int stage ){
	exit( 0 );
}

void MainScene::PlayOnclick( int stage ){
	PlayScene* scene = dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetScene("play"));
	Engine::GameEngine::GetInstance().ChangeScene("play");
}
