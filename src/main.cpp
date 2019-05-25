// [main.cpp]
// this template is provided for the 2D tower defense game.
// Program entry point.
// Returns program exit code.
#define MYPC
#ifdef MYPC
#define WIDTH 1366
#define HEIGHT 768
#else
#define WIDTH 1920
#define HEIGHT 1080
#endif

#include "GameEngine.hpp"
#include "LOG.hpp"
#include "LoseScene.hpp"
#include "PlayScene.hpp"
#include "StageSelectScene.hpp"
#include "WinScene.hpp"
#include "MainScene.hpp"
#include "SettingScene.hpp"

int main( int argc, char ** argv ){
	Engine::LOG::SetConfig( true );
	Engine::GameEngine& game = Engine::GameEngine::GetInstance();
	game.AddNewScene( "main", new MainScene() );
	game.AddNewScene( "setting", new SettingScene() );
	game.AddNewScene( "stage-select", new StageSelectScene() );
	game.AddNewScene( "play", new PlayScene() );
	game.AddNewScene( "lose", new LoseScene() );
	game.AddNewScene( "win", new WinScene() );
	// TODO 1 (1/2): Add a New Scene here and change the start scene below.
	game.Start( "main", 60, WIDTH, HEIGHT );
	return 0;
}
