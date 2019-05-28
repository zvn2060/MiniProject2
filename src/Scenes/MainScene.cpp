#include <functional>
#include <memory>
#include <string>
#include "AudioHelper.hpp"
#include "GameEngine.hpp"
#include "ImageButton.hpp"
#include "Label.hpp"
#include "Point.hpp"
#include "Resources.hpp"
#include "Slider.hpp"

#include "PlayScene.hpp"
#include "MainScene.hpp"
#include "SettingScene.hpp"

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
	btn->SetOnClickCallback( std::bind( &MainScene::PlayOnclick, this, 1 ) );
	AddNewControlObject( btn );
	
	AddNewObject( new Engine::Label( "戰鬥 !", "SoukouMincho.ttf", 48, halfW, halfH + 250, 255, 0, 0, 255, 0.5, 0.5 ) );
	AudioHelper::PlayBGM( "select.ogg" );
}

void MainScene::SettingOnClick( int stage ){
	Engine::GameEngine::GetInstance().ChangeScene( "setting" );
}

void MainScene::BackOnclick( int stage ){
	exit( 0 );
}

void MainScene::PlayOnclick( int stage ){
	PlayScene* scene = dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetScene("play"));
	scene->MapId = stage;
	Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}
