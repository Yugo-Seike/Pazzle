#include "DxLib.h"
#include "Area.h"
#include "Questions.h"
//#include <string.h>
//#include <tchar.h>
//#include <iostream>

#define debug_mode 1

#define SIZE_OF_BLOCK_X 45
#define SIZE_OF_BLOCK_Y 45

#define OFFSET_X        150
#define OFFSET_Y        80

#define BORDER_WIDTH    1
#define BORDER_COLOR    GetColor(57, 255, 255)

#define White           GetColor(255, 255, 255)         //色の取得
#define Black           GetColor(0, 0, 0)               //色の取得

#define CHAR_BUF        4


char KeyBuf[256];
int Mouse = GetMouseInput();
int color;
int title,a;
int masu,back,sikaku,dekasikaku,modoru;



bool is_correct(const char* GameBlocks[NUM_OF_BLOCK_Y + NUM_OF_HINT][NUM_OF_BLOCK_X + NUM_OF_HINT], char BlockStatus[NUM_OF_BLOCK_Y][NUM_OF_BLOCK_X][CHAR_BUF]);
void initPazzle(int qnum, const char* GameBlocks[NUM_OF_BLOCK_Y + NUM_OF_HINT][NUM_OF_BLOCK_X + NUM_OF_HINT]);
int Opening();
int Ending();
void loadFonts(LPCSTR font_path);
void unloadFonts(LPCSTR font_path);
int function_status = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    int qnum = 0, qidx = 0;
    //LPCSTR font_path = "数式フォントver1.5.ttf"; 
    LPCSTR font_path = "NagomiGokubosoGothic-ExtraLight.otf"; //読み込むフォントファイルのパス
    DxLib_Init();
    SetGraphMode(1280, 1024, 32);
    ChangeWindowMode(TRUE);
    if (DxLib_Init() == -1) return -1;                  //ＤＸライブラリ初期化処理 エラーが起きたら終了 

    loadFonts(font_path);
    ChangeFont("なごみ極細ゴシック ExtraLight", DX_CHARSET_DEFAULT);
    SetDrawScreen(DX_SCREEN_BACK);                      //描画先を裏画面に設定
    GetScreenState(&window_x, &window_y, &color);
    setPositions();

    while (1) {
        ClearDrawScreen();                              //裏画面のデータを全て削除
        GetHitKeyStateAll(KeyBuf);                      //すべてのキーの状態を得る
        SetMouseDispFlag(TRUE);

        switch (function_status) {
            case 0:
                function_status = Opening();
                break;

            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
                qnum = function_status;
                qidx = function_status - 1;
                initPazzle(qnum, GameBlocks[qidx]);

                if (KeyBuf[KEY_INPUT_SPACE] == 1) function_status++;    //なんのためにしているのかわからない
                break;

            case 13:
                function_status = Ending();
                break;

            default:
                DxLib_End();                                // ＤＸライブラリ使用の終了処理
                return 0;
                break;
        }

        if (ProcessMessage() == -1) break;                  //エラーが起きたら終了

        ScreenFlip();                                       // 裏画面データを表画面へ反映
    }
    unloadFonts(font_path);                                 //フォントのアンロード
    
    DxLib_End();                                            // ＤＸライブラリ使用の終了処理
    return 0;                                               // ソフトの終了
}

void initPazzle(int qnum, const char* GameBlocks[NUM_OF_BLOCK_Y + NUM_OF_HINT][NUM_OF_BLOCK_X + NUM_OF_HINT]) {
    char qnum_str[8] = "";
    if (debug_mode) printfDx("called!");
    back = LoadGraph("sozai/background1.png");
    DrawExtendGraph(0, 0, window_x, window_y, back, FALSE);

    sikaku = LoadGraph("sozai/sikaku.png");
    DrawExtendGraph(150, 30, 450, 80, sikaku, TRUE);

    //dekasikaku = LoadGraph("sozai/dekasikaku.png");
    //DrawExtendGraph(430, 170, 610, 470, dekasikaku, TRUE);

    //sprintf_s(qnum_str, "%d%s", qnum, "問目");

    //DrawString(120, 60, qnum_str, White);

    modoru = LoadGraph("sozai/戻るボタン.png");
    DrawExtendGraph(10, 400, 150, 480, modoru, TRUE);
    Area* modomodo = new Area(10, 400, 150, 480);
    

    SetFontSize(32);
    DrawString(150, 40, Question_name[qnum-1], White);
    SetFontSize(25);

    Area* GameDrowing[NUM_OF_BLOCK_Y][NUM_OF_BLOCK_X];
    char BlockStatus[NUM_OF_BLOCK_Y][NUM_OF_BLOCK_X][CHAR_BUF];
    (new Area(OFFSET_X - BORDER_WIDTH,
        OFFSET_Y - BORDER_WIDTH,
        SIZE_OF_BLOCK_X * NUM_OF_BLOCK_X + BORDER_WIDTH,
        SIZE_OF_BLOCK_Y * NUM_OF_BLOCK_Y + BORDER_WIDTH
    ))->DrawBox(BORDER_COLOR, true);

    //各ブロックを作成
    for (int y = 0; y < NUM_OF_BLOCK_Y; y++) {
        for (int x = 0; x < NUM_OF_BLOCK_X; x++) {
            GameDrowing[y][x] = new Area(x * SIZE_OF_BLOCK_X + OFFSET_X, y * SIZE_OF_BLOCK_Y + OFFSET_Y, SIZE_OF_BLOCK_X - BORDER_WIDTH, SIZE_OF_BLOCK_Y - BORDER_WIDTH);
            GameDrowing[y][x]->DrawBox(White, true);
            strcpy_s(BlockStatus[y][x], sizeof(BlockStatus[y][x]), W);
            if (debug_mode) {
                //デバッグモードでは解答を表示
                strcpy_s(BlockStatus[y][x], sizeof(BlockStatus[y][x]), GameBlocks[y][x]);
                if (GameBlocks[y][x] == W) GameDrowing[y][x]->DrawBox(White, true);
                if (GameBlocks[y][x] == B) GameDrowing[y][x]->DrawBox(Black, true);
            }
        }
    }

    //ヒントの表示
    for (int y = 0; y < NUM_OF_BLOCK_Y + 4; y++) {
        for (int x = y < NUM_OF_BLOCK_Y ? NUM_OF_BLOCK_X : 0; x < (y < NUM_OF_BLOCK_Y ? NUM_OF_BLOCK_X + NUM_OF_HINT : NUM_OF_BLOCK_X); x++) {
            if (strcmp(GameBlocks[y][x], " ") != 0) {
                DrawString(x * SIZE_OF_BLOCK_X + OFFSET_X, y * SIZE_OF_BLOCK_Y + OFFSET_Y, GameBlocks[y][x], White);
            }
        }
    }

    ScreenFlip();
    while (1) {
        char blockmode[CHAR_BUF] = BLANK;
        WaitKey();
        while (GetMouseInput()) {
            for (int y = 0; y < NUM_OF_BLOCK_Y; y++) {
                for (int x = 0; x < NUM_OF_BLOCK_X; x++) {
                    if (GameDrowing[y][x]->mouse_in()) {
                        //クリック時の挙動が変。要デバッグ
                        if (strcmp(blockmode, BLANK) == 0) {
                            //左クリック：白→黒→×を順次
                            if(GetMouseInput() & MOUSE_INPUT_LEFT){
                                if (strcmp(BlockStatus[y][x], W) == 0) {
                                    strcpy_s(blockmode, sizeof(blockmode), B);
                                }
                                else if (strcmp(BlockStatus[y][x], B) == 0) {
                                    strcpy_s(blockmode, sizeof(blockmode), X);
                                }
                                else {
                                    strcpy_s(blockmode, sizeof(blockmode), W);
                                }
                            }
                            //右クリック：白→×を交互
                            if (GetMouseInput() & MOUSE_INPUT_RIGHT){
                                if (strcmp(BlockStatus[y][x], X) == 0) {
                                    strcpy_s(blockmode, sizeof(blockmode), W);
                                }
                                else {
                                    strcpy_s(blockmode, sizeof(blockmode), X);
                                }
                            }
                        }
                        //success / failed画面の表示後は、下の【「ここから」～「ここまで」を、xとyのループ内で回す】という処理を、一回だけ
                        /* ここから */
                        GameDrowing[y][x]->DrawBox(strcmp(blockmode, W) == 0 ? White : Black, true);
                        if (strcmp(blockmode, X) == 0) GameDrowing[y][x]->DrawX(White);
                        strcpy_s(BlockStatus[y][x], sizeof(BlockStatus[y][x]), blockmode);
                        /* ここまで */
                        ScreenFlip();
                    }
                }
            }
            if (modomodo->mouse_in()) {
                function_status = 0;
                return;
            }
            if (false) { //TODO: 答え合わせのボタンを押すと
                if (is_correct(GameBlocks, BlockStatus)) {
                    break;
                }
                else {
                    //TODO: 間違いの場合の処理（→再度入力待ちに）
                    if (debug_mode) printfDx("incorrect!");
                }
            }
        }
    }

    if (debug_mode) printfDx("correct!");
    //TODO: 正解画面→メニューへ戻る処理

}

int Opening() {
    //DrawString(100, 100, "タイトル画面", White);

    //ChangeWindowMode(true);

    //LoadGraphScreen(0, 0, "sozai/title.png", TRUE);
    title = LoadGraph("sozai/title2.png");
    DrawExtendGraph(0, 0, window_x, window_y, title, FALSE);

    
    if (KeyBuf[KEY_INPUT_W] == 1) {
        return 1;
    }
    if (debug_mode) {
        for (int i = 0; i < NUM_OF_QUESTION; i++) {
            Question_Button[i]->DrawBox(White, false);
        }
    }
    ScreenFlip();
    WaitKey();
    if (GetMouseInput() & MOUSE_INPUT_LEFT) {
        for (int i = 0; i < NUM_OF_QUESTION; i++) {
            if (Question_Button[i]->mouse_in()) {
                return i + 1;
            }
        }
    }
}

int Ending() {
    DrawString(120, 40, "END", White);
    if (KeyBuf[KEY_INPUT_W] == 1) return 14;
}

void loadFonts(LPCSTR font_path) {
    // フォント読込エラー処理
    if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) <= 0) MessageBox(NULL, "フォント読込失敗", "", MB_OK);
}

void unloadFonts(LPCSTR font_path) {
    if (!RemoveFontResourceEx(font_path, FR_PRIVATE, NULL)) MessageBox(NULL, "remove failure", "", MB_OK);
}

bool is_correct(const char *GameBlocks[NUM_OF_BLOCK_Y + NUM_OF_HINT][NUM_OF_BLOCK_X + NUM_OF_HINT], char BlockStatus[NUM_OF_BLOCK_Y][NUM_OF_BLOCK_X][CHAR_BUF]) {
    bool rtn = true;
    for (int x = 0; x < NUM_OF_BLOCK_X; x++) {
        for (int y = 0; y < NUM_OF_BLOCK_X; y++) {
            rtn &= (strcmp(GameBlocks[y][x], BlockStatus[y][x]) == 0);
        }
    }
    return rtn;
}