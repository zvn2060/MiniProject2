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
	AudioHelper::PlayBGM( "select.ogg" );
	sliderBGM->SetValue( AudioHelper::BGMVolume );
	sliderSFX->SetValue( AudioHelper::SFXVolume );
};

void SettingScene::BackOnClick( int stage ){
	MainScene * scene = dynamic_cast<MainScene *>(Engine::GameEngine::GetInstance().GetScene( "main" ));
	Engine::GameEngine::GetInstance().ChangeScene( "main" );
}

void SettingScene::BGMSlideOnValueChanged( float value ){
	AudioHelper::BGMVolume = value;
}

void SettingScene::SFXSlideOnValueChanged( float value ){
	AudioHelper::SFXVolume = value;
}
