export module Score;
import ObjectBase;
import Player;

export class Score : public ObjectBase {
public:
    Score();
    virtual ~Score();

    void Draw() override;

    void AddScore(const int score) { this->score += score; }
    int GetScore() const { return score; }
    void SetPlayer(Player* player) { this->player = player; }

private:
    int score;
    Player* player;
};
