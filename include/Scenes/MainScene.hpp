#ifndef MAINSCENE_HPP
#define MAINSCENE_HPP
#include "IScene.hpp"
#include "GameEngine.hpp"
#include "ImageButton.hpp"

class MainScene final : public Engine::IScene{
private:
	ALLEGRO_SAMPLE_INSTANCE* bgmInstance;
public:
	explicit MainScene() = default;
	void Initialize() override;
	void PlayOnClick(int stage);

};

#endif //MAINSCENE_HPP
