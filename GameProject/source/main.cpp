/*
*
* Commnet
*
*/
#include <Windows.h>; // WinMain
#include "GameMain.h";
import DxLibWrapper;

namespace {
    // 画面設定
    constexpr auto SCREEN_W = 1280;    ///< 画面の横解像度
    constexpr auto SCREEN_H = 720;     ///< 画面の縦解像度
    constexpr auto SCREEN_DEPTH = 32;  ///< １ドットあたりのビット数
} // namespace

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow) {
    // 初期化
    // -------------------------------------------------------------------------
    // ＤＸライブラリ初期化処理
    DW::SetGraphMode(SCREEN_W, SCREEN_H, SCREEN_DEPTH);  // 画面の解像度を横1280×縦720、1ドットあたり32ビットに指定する

    DW::ChangeWindowMode(true);    // ウィンドウモードに指定する

    if (DW::DxLib_Init() == -1) {  // エラーが起きたら直ちに終了
        return -1;
    }

    DW::SetDrawScreen(DW::DW_SCREEN_BACK);  // 描画先画面を裏画面にセット

    // ゲームメイン
    GameMain* gameMain = new GameMain();

    gameMain->Init();

    // メインループ
    while (DW::ProcessMessage() == 0) {
        gameMain->Input();

        if (!gameMain->Process()) {
            break;
        }

        DW::ClearDrawScreen();
        gameMain->Draw();
        DW::ScreenFlip();
    }

    delete gameMain;

    // 解放
    // ---------------------------------------------------------------------------
    DW::DxLib_End();  // ＤＸライブラリ使用の終了処理

    // 終了
    return 0;
}

