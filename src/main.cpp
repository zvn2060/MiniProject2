// [main.cpp]
// this template is provided for the 2D tower defense game.
// Program entry point.
// Returns program exit code.

#include "GameEngine.hpp"
#include "LOG.hpp"
#include "StageSelectScene.hpp"
#include "PlayScene.hpp"
#include "WinScene.hpp"
#include "LoseScene.hpp"
#include "MainScene.hpp"
#include "SettingScene.hpp"

void CreateScenes();

int main( int argc, char ** argv ){
	Engine::LOG::SetConfig( true );
	Engine::GameEngine& game = Engine::GameEngine::GetInstance();
	CreateScenes();
	
	game.Start( "main", 60, 1600, 832 );
	return 0;
}

void CreateScenes(){
	Engine::GameEngine & game = Engine::GameEngine::GetInstance();
	game.AddNewScene( "main", new MainScene() );
	game.AddNewScene( "setting", new SettingScene() );
	game.AddNewScene( "stage-select", new StageSelectScene() );
	game.AddNewScene( "play", new PlayScene() );
	game.AddNewScene( "lose", new LoseScene() );
	game.AddNewScene( "win", new WinScene() );
}
