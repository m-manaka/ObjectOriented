export module Score;
import ObjectBase;
import Player;

export class Score final : public ObjectBase {
public:
    Score();
    virtual ~Score();

    void Draw() override;

    void AddScore(const int score) { this->score += score; }
    [[nodiscard]] int GetScore() const { return score; }
    void SetPlayer(Player* player) { this->player = player; }

private:
    int score{ 0 };
    Player* player{ nullptr };
};
