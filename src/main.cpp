#define isPC

#ifdef isPC
#define WIDTH 1366
#define HEIGHT 768
#else
#define WIDTH 1920
#define HEIGHT 1080
#endif

// [main.cpp]
// this template is provided for the 2D tower defense game.
// Program entry point.
// Returns program exit code.
#include "GameEngine.hpp"
#include "LOG.hpp"
#include "Scenes/StageSelectScene.hpp"
#include "Scenes/PlayScene.hpp"
#include "Scenes/WinScene.hpp"
#include "Scenes/LoseScene.hpp"
#include "Scenes/MainScene.hpp"
#include "Scenes/SettingScene.hpp"

int main( int argc, char **argv) {
	Engine::LOG::SetConfig( true);
	Engine::GameEngine& game = Engine::GameEngine::GetInstance();
	
	//<editor-fold defaultstate="collapsed" desc="Scenes create">
	game.AddNewScene( "main", new MainScene());
	game.AddNewScene( "setting", new SettingScene() );
	game.AddNewScene( "play", new PlayScene());
	game.AddNewScene( "lose", new LoseScene());
	game.AddNewScene( "win", new WinScene());
	//</editor-fold>
	
	// TODO 1 (1/2): Add a New Scene here and change the start scene below.
	game.Start( "main", 60, WIDTH, HEIGHT );
	return 0;
}
