#include <Label.hpp>
#include <Resources.hpp>
#include "Scenes/SettingScene.hpp"
#include "Scenes/MainScene.hpp"
#include "AudioHelper.hpp"
#include "Slider.hpp"
#include "LOG.hpp"

void SettingScene::Initialize(){
	int w = Engine::GameEngine::GetInstance().GetScreenSize().x;    //set window width
	int h = Engine::GameEngine::GetInstance().GetScreenSize().y;    //set window height
	int halfW = w / 2;
	int halfH = h / 2;
	Engine::ImageButton * btn;
	btn = new Engine::ImageButton( "UI/return.png", "UI/return_CL.png", w - 100, 0, 100, 100 );
	btn->SetOnClickCallback( std::bind( &SettingScene::BackOnClick, this, 1 ) );
	AddNewControlObject( btn );
	
	Slider * sliderBGM, * sliderSFX;
	sliderBGM = new Slider( 40 + halfW - 95, halfH - 50 - 2, 190, 4 );
	sliderBGM->SetOnValueChangedCallback(
			std::bind( &SettingScene::BGMSlideOnValueChanged, this, std::placeholders::_1 ) );
	AddNewControlObject( sliderBGM );
	AddNewObject(
			new Engine::Label( "BGM: ", "pirulen.ttf", 28, 40 + halfW - 60 - 95, halfH - 50, 255, 255, 255, 255, 0.5,
							   0.5 ) );
	
	sliderSFX = new Slider( 40 + halfW - 95, halfH + 50 - 2, 190, 4 );
	sliderSFX->SetOnValueChangedCallback(
			std::bind( &SettingScene::SFXSlideOnValueChanged, this, std::placeholders::_1 ) );
	AddNewControlObject( sliderSFX );
	AddNewObject(
			new Engine::Label( "SFX: ", "pirulen.ttf", 28, 40 + halfW - 60 - 95, halfH + 50, 255, 255, 255, 255, 0.5,
							   0.5 ) );
	
	// Not a safe way, however we only free while change scene, so it's fine.
	bgmInstance = al_create_sample_instance( Engine::Resources::GetInstance().GetSample( "select.ogg" ).get() );
	al_set_sample_instance_playmode( bgmInstance, ALLEGRO_PLAYMODE_LOOP );
	al_attach_sample_instance_to_mixer( bgmInstance, al_get_default_mixer() );
	al_play_sample_instance( bgmInstance );
	sliderBGM->SetValue( AudioHelper::BGMVolume );
	sliderSFX->SetValue( AudioHelper::SFXVolume );
};

void SettingScene::BackOnClick( int stage ){
	MainScene * scene = dynamic_cast<MainScene *>(Engine::GameEngine::GetInstance().GetScene( "main" ));
	Engine::GameEngine::GetInstance().ChangeScene( "main" );
}

void SettingScene::BGMSlideOnValueChanged( float value ){
	al_set_sample_instance_gain( bgmInstance, value );
	AudioHelper::BGMVolume = value;
}

void SettingScene::SFXSlideOnValueChanged( float value ){
	AudioHelper::SFXVolume = value;
}
