module; // グローバルモジュールフラグメント
#include <DxLib.h>
export module DxLibWrapper;

// 使用したいDXライブラリの関数をC++の関数としてラップし、exportする
export namespace DW {
    using ::SetGraphMode;
    using ::ChangeWindowMode;
    using ::DxLib_Init;
    using ::SetDrawScreen;
    using ::ProcessMessage;
    using ::ClearDrawScreen;
    using ::ScreenFlip;
    using ::DxLib_End;

    using ::LoadGraph;
    using ::DeleteGraph;
    using ::DrawGraph;

    using ::SetFontSize;
    using ::GetFontSize;
    using ::GetColor;
    using ::DrawString;
    using ::DrawFormatString;

    using ::GetJoypadInputState;

    constexpr auto DW_TRUE = TRUE;
    constexpr auto DW_SCREEN_BACK = DX_SCREEN_BACK;

    constexpr auto DW_PAD_INPUT_LEFT = PAD_INPUT_LEFT;
    constexpr auto DW_PAD_INPUT_RIGHT = PAD_INPUT_RIGHT;
    constexpr auto DW_PAD_INPUT_UP = PAD_INPUT_UP;
    constexpr auto DW_PAD_INPUT_DOWN = PAD_INPUT_DOWN;

    constexpr auto DW_PAD_INPUT_A = PAD_INPUT_A;
    constexpr auto DW_PAD_INPUT_7 = PAD_INPUT_7;
    constexpr auto DW_PAD_INPUT_9 = PAD_INPUT_9;
    constexpr auto DW_PAD_INPUT_10 = PAD_INPUT_10;
    constexpr auto DW_INPUT_KEY_PAD1 = DX_INPUT_KEY_PAD1;
}
