module;
#include <tchar.h>
module BackGround;
import ObjectBase;

// 継承先クラスのコンストラクタに続けて ": 基底クラスコンストラクタ"
// と呼び出せる
BackGround::BackGround(const TCHAR* fileName) : ObjectBase(fileName) {}

BackGround::~BackGround() {}
