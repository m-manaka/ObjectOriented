#pragma once
#include <tchar.h>

// 本プログラムの全てのオブジェクトの基底クラス
class ObjectBase {
public:
    ObjectBase();  // コンストラクタ
    // コンストラクタは引数を変えれば何個でも作成可能
    ObjectBase(const TCHAR* fileName);
    virtual ~ObjectBase(); // デストラクタ

    virtual void Init();
    virtual void Load(const TCHAR* fileName);
    // 基本的に class でのメソッド引数には const をつける
    virtual void Process(const int key, const int trriger);
    virtual void Draw();

    int GetCgHandle() const { return cgHandle; }
    int GetX() const { return x; }
    int GetY() const { return y; }
    int GetW() const { return w; }
    int GetH() const { return h; }

    void SetCgHandle(const int cgHandle) { this->cgHandle = cgHandle; }
    void SetX(const int x) { this->x = x; }
    void SetY(const int y) { this->y = y; }
    void SetW(const int w) { this->w = w; }
    void SetH(const int h) { this->h = h; }

    void SetCgHandleDeleteLock(const bool cgHandleDeleteLock) {
        this->cgHandleDeleteLock = cgHandleDeleteLock;
    }

protected:
    // protected にして継承先クラスで使用可能にする
    // 下記のメンバ変数が、今回の基底に相応しい種類と設計する
    int cgHandle;
    int x;
    int y;
    int w;
    int h;

    bool cgHandleDeleteLock;
};
