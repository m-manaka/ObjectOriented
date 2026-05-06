export module Enemy;
import ObjectBase;

export class Enemy final : public ObjectBase {
public:
    Enemy(const int width, const int height, const int cgHandle);
    virtual ~Enemy();

    void Init() override;
    void Process(const int key, const int trigger) override;
    void Draw() override;

    [[nodiscard]] bool IsUse() const { return use; }
    void SetUse(const bool use) { this->use = use; }

    [[nodiscard]] int GetSpeedX() const { return spd_x; }
    [[nodiscard]] int GetSpeedY() const { return spd_y; }

    void SetSpeedX(const int spd_x) { this->spd_x = spd_x; }
    void SetSpeedY(const int spd_y) { this->spd_y = spd_y; }

private:
    void InitPos();

    bool use{ false };
    int spd_x{ 0 };
    int spd_y{ 0 };

    int screenWidth{ 0 };
    int screenHeight{ 0 };
};