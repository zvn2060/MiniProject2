#ifndef MAINSCENE_HPP
#define MAINSCENE_HPP

#include <allegro5/allegro_audio.h>
#include "IScene.hpp"


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
