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

int main(int argc, char **argv) {
	Engine::LOG::SetConfig(true);
	Engine::GameEngine& game = Engine::GameEngine::GetInstance();
	game.AddNewScene("main", new MainScene());
	game.AddNewScene("play", new PlayScene());
	game.AddNewScene("lose", new LoseScene());
	game.AddNewScene("win", new WinScene());
	// TODO 1 (1/2): Add a New Scene here and change the start scene below.
	game.Start("main", 60, 1600, 832);
	game.ChangeScene("play");
	return 0;
}
