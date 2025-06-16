#pragma once
#include <vector>
#include "Bullet.h"
#include "ObjectBase.h"

class Player : public ObjectBase {
public:
    Player(const int width,
           const int height,
           const int cgBullet,
           const TCHAR* fileName);
    Player(const int width, const int height, const int cgBullet);
    virtual ~Player();

    void Init() override;
    void Process(const int key, const int trriger) override;
    void Draw() override;

    void SetDamage();

    int GetSpeed() const { return spd; }
    void SetSpeed(const int spd) { this->spd = spd; }

    int GetLife() const { return life; }
    void SetLife(const int life) { this->life = life; }

    std::vector<Bullet*>& GetBullet() { return bullet; }

private:
    void AddPlayerBullet();

    int spd;
    int life;

    int screenWidth;
    int screenHeight;

    std::vector<Bullet*> bullet;
};
