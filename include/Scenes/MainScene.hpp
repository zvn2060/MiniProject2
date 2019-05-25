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
	
	void SettingOnClick( int stage );
	
	void BackOnclick( int stage );
	
	void PlayOnclick( int stage );
};

#endif //MAINSCENE_HPP
