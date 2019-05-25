#include "Scenes/SettingScene.hpp"
#include "Scenes/MainScene.hpp"
#include "AudioHelper.hpp"
#include "Slider.hpp"

void SettingScene::Initialize(){
	int w = Engine::GameEngine::GetInstance().GetScreenSize().x;    //set window width
	int h = Engine::GameEngine::GetInstance().GetScreenSize().y;    //set window height
	int halfW = w / 2;
	int halfH = h / 2;
	Engine::ImageButton * btn;
	btn = new Engine::ImageButton( "UI/return.png", "UI/return_CL.png", w - 100, 0, 100, 100 );
	btn->SetOnClickCallback( std::bind( &SettingScene::BackOnClick, this, 1 ) );
	AddNewControlObject( btn );
};

void SettingScene::BackOnClick( int stage ){
	MainScene * scene = dynamic_cast<MainScene *>(Engine::GameEngine::GetInstance().GetScene( "main" ));
	Engine::GameEngine::GetInstance().ChangeScene( "main" );
}
