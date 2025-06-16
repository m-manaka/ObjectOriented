#pragma once
#include <tchar.h>

// �{�v���O�����̑S�ẴI�u�W�F�N�g�̊��N���X
class ObjectBase {
public:
    ObjectBase();  // �R���X�g���N�^
    // �R���X�g���N�^�͈�����ς���Ή��ł��쐬�\
    ObjectBase(const TCHAR* fileName);
    virtual ~ObjectBase(); // �f�X�g���N�^

    virtual void Init();
    virtual void Load(const TCHAR* fileName);
    // ��{�I�� class �ł̃��\�b�h�����ɂ� const ������
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
    // protected �ɂ��Čp����N���X�Ŏg�p�\�ɂ���
    // ���L�̃����o�ϐ����A����̊��ɑ���������ނƐ݌v����
    int cgHandle;
    int x;
    int y;
    int w;
    int h;

    bool cgHandleDeleteLock;
};
