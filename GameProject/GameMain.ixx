export module GameMain;
import std;
import ObjectBase;
import Player;
import Enemy;
import Score;

export class GameMain {
public:
    GameMain();
    virtual ~GameMain();

    void Init();
    void Input();
    bool Process();
    void Draw();

private:
    void Save() const;
    void SavePlayer(const Player* player) const;
    void SaveEnemyList(const std::vector<Enemy*>& enemyList) const;
    void SaveScore(const Score* score) const;

    void Load();
    void DeleteOldObjects();
    Player* LoadPlayer() const;
    std::vector<Enemy*> LoadEnemyList() const;
    Score* LoadScore() const;

    void Create();
    void SetupScore();
    bool IsHitBox(const int x1,
        const int y1,
        const int w1,
        const int h1,
        const int x2,
        const int y2,
        const int w2,
        const int h2) const;
    void HitCheckPlayerEnemy(Player* player) const;
    void HitCheckEnemyPlayerBullet(Player* player) const;
    [[nodiscard]] Player* GetPlayer() const;
    [[nodiscard]] Score* GetScore() const;

    int inputKey{ 0 };
    int inputTrg{ 0 };

    // C++ の STL である std::vector を配列の変わりに使う
    std::vector<ObjectBase*> objectList;

    // Save / Load の為に増やしやメンバ
    int cgBullet{ -1 };
    int cgEnemy{ -1 };

    // ポーズ(&Save/Load)機能
    bool isPause{ false };
    bool isSelectSave{ true };
};
