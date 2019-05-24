#include "Scenes/MainScene.hpp"
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
	btn = new Engine::ImageButton("main/setbtn.png", "main/setbtnclick.png", 0, 0, 100, 100);
	btn->SetOnClickCallback(std::bind(&MainScene::PlayOnClick, this, 1));
	AddNewControlObject(btn);
	AddNewObject(new Engine::Label("Stage 1", "pirulen.ttf", 48, halfW, halfH / 2, 0, 0, 0, 255, 0.5, 0.5));
	Slider *sliderBGM, *sliderSFX;
	sliderBGM = new Slider(40 + halfW - 95, halfH - 50 - 2, 190, 4);
	bgmInstance = al_create_sample_instance(Engine::Resources::GetInstance().GetSample("select.ogg").get());
	al_set_sample_instance_playmode(bgmInstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(bgmInstance, al_get_default_mixer());
	al_play_sample_instance(bgmInstance);
	sliderBGM->SetValue(AudioHelper::BGMVolume);
	sliderSFX->SetValue(AudioHelper::SFXVolume);
}
void MainScene::PlayOnClick(int stage) {
	PlayScene* scene = dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetScene("play"));
	scene->MapId = stage;
	Engine::GameEngine::GetInstance().ChangeScene("play");
}


