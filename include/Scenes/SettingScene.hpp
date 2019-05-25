#ifndef SETTINGSCENE_HPP
#define SETTINGSCENE_HPP

#include "GameEngine.hpp"
#include "IScene.hpp"
#include "ImageButton.hpp"

class SettingScene final : public Engine::IScene{
public:
	explicit SettingScene() = default;
	
	void Initialize() override;
	
	void BackOnClick( int stage );
};

#endif //SETTINGSCENE_HPP
