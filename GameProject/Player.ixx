module;
#include <tchar.h>
export module Player;
import std;
import Bullet;
import ObjectBase;

export class Player final : public ObjectBase {
public:
    Player(const int width,
        const int height,
        const int cgBullet,
        const TCHAR* fileName);
    Player(const int width, const int height, const int cgBullet);
    virtual ~Player();

    void Init() override;
    void Process(const int key, const int trigger) override;
    void Draw() override;

    void SetDamage();

    [[nodiscard]] int GetSpeed() const { return spd; }
    void SetSpeed(const int spd) { this->spd = spd; }

    [[nodiscard]] int GetLife() const { return life; }
    void SetLife(const int life) { this->life = life; }

    [[nodiscard]] std::vector<Bullet*>& GetBullet() { return bullet; }
    [[nodiscard]] const std::vector<Bullet*>& GetBullet() const { return bullet; }

private:
    void AddPlayerBullet();

    int spd{ 0 };
    int life{ 0 };

    int screenWidth{ 0 };
    int screenHeight{ 0 };

    std::vector<Bullet*> bullet;
};
