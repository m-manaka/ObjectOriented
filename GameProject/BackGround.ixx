module;
#include <tchar.h>
export module BackGround;
import ObjectBase;

// 背景画像をロードして描画だけするクラス
export class BackGround : public ObjectBase {
public:
    BackGround(const TCHAR* fileName);
    virtual ~BackGround();
};
