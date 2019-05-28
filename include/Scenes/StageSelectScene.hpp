#ifndef STAGESELECTSCENE_HPP
#define STAGESELECTSCENE_HPP
#include "IScene.hpp"
#include "GameEngine.hpp"
#include "ImageButton.hpp"

class StageSelectScene final : public Engine::IScene {
private:
	ALLEGRO_SAMPLE_INSTANCE* bgmInstance;
public:
	explicit StageSelectScene() = default;
	void Initialize() override;
	void PlayOnClick(int stage);
	void ConstructStageList();
};

#endif // STAGESELECTSCENE_HPP
