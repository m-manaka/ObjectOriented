module Score;
import DxLibWrapper;

constexpr auto SCORE_POS_X = 32;
constexpr auto SCORE_POS_Y = 32;

Score::Score() : ObjectBase() {}

Score::~Score() {}

void Score::Draw() {
    if (player == nullptr) {
        return;
    }

    static const auto scoreColor = DW::GetColor(255, 0, 0);

    // ライフ、スコア表示
    DW::DrawFormatString(SCORE_POS_X, SCORE_POS_Y, scoreColor, "Life:%d   Score:%d", player->GetLife(), score);
}
