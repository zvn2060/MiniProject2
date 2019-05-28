#include "PlayScene.hpp"
#include "SlimeTurret.hpp"
#include "StickyBullet.hpp"
#include "AudioHelper.hpp"

const int SlimeTurret::Price = 70;
SlimeTurret::SlimeTurret(float x, float y) :
    Turret("play/tower-base.png", "play/turret-7.png", x, y, 200, Price, 0.5) {
    // Move center downward, since we the turret head is slightly biased upward.
    Anchor.y += 8.0f / GetBitmapHeight();
}
void SlimeTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new StickyBullet(Position + normalized * 36, diff, rotation, this));
    AudioHelper::PlayAudio("gun.wav");
}
