#ifndef MINI2_SLIMETURRET_HPP
#define MINI2_SLIMETURRET_HPP

#include "PlayScene.hpp"
#include "Bullet.hpp"
#include "Turret.hpp"

class PlayScene;
class SlimeTurret: public Turret {
public:
    static const int Price;
    SlimeTurret(float x, float y);
    void CreateBullet() override;
};


#endif //MINI2_SLIMETURRET_HPP
