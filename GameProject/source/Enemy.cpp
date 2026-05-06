module Enemy;
import std;
import DxLibWrapper;

constexpr auto ENEMY_WIDTH = 32;
constexpr auto ENEMY_HEIGHT = 32;
constexpr auto ENEMY_SPEED_X = 8;
constexpr auto ENEMY_SPEED_Y = 4;

Enemy::Enemy(const int width, const int height, const int cgHandle) : ObjectBase() {
    screenWidth = width;
    screenHeight = height;

    this->cgHandle = cgHandle;
}

Enemy::~Enemy() {}

void Enemy::InitPos() {
    static std::mt19937 rng{ std::random_device{}() };
    std::uniform_int_distribution<int> dist(0, screenWidth - 1);

    x = dist(rng);
    y = (0 - h);
}

void Enemy::Init() {
    use = true;
    w = ENEMY_WIDTH;
    h = ENEMY_HEIGHT;
    spd_x = ENEMY_SPEED_X;
    spd_y = ENEMY_SPEED_Y;

    InitPos();
}

void Enemy::Process([[maybe_unused]] const int key, [[maybe_unused]] const int trigger) {
    // MoveEnemy に相当
    // この敵は使用中か？
    if (use) {
        // この敵は使用中である
        // 敵の移動処理
        x += spd_x;
        y += spd_y;

        // 横バウンドの判定
        if (x < 0 || x + w > screenWidth) {
            spd_x *= -1;
        }

        // 画面下に出る判定
        if (y > screenHeight) {
            InitPos();
        }
    }
}

void Enemy::Draw() {
    if (!use) {
        return;
    }

    ObjectBase::Draw();
}
