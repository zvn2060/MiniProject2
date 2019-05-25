#ifndef SETTINGSCENE_HPP
#define SETTINGSCENE_HPP

#include <allegro5/allegro_audio.h>
#include "IScene.hpp"
#include "GameEngine.hpp"
#include "ImageButton.hpp"

class SettingScene final : public Engine::IScene{
private:
	ALLEGRO_SAMPLE_INSTANCE * bgmInstance;
public:
	explicit SettingScene() = default;
	
	void Initialize() override;
	
	void BackOnClick( int stage );
	
	void BGMSlideOnValueChanged( float value );
	
	void SFXSlideOnValueChanged( float value );
};

#endif //SETTINGSCENE_HPP
