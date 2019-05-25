#ifndef STICKYBULLET_HPP
#define STICKYBULLET_HPP

#include "Bullet.hpp"

class Enemy;

class Turret;
namespace Engine{
	struct Point;
}  // namespace Engine

class StickyBullet : public Bullet{
public:
	explicit StickyBullet( Engine::Point position, Engine::Point forwardDirection, float rotation, Turret * parent );
	
	void OnExplode( Enemy * enemy ) override;
};

#endif // STICKYBULLET_HPP
