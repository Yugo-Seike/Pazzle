#include "DxLib.h"
#include "Area.h"
//#include <tchar.h>
//#include <iostream>

#define NUM_OF_BLOCK_X	15
#define NUM_OF_BLOCK_Y	15

#define NUM_OF_HINT		8

#define SIZE_OF_BLOCK_X 20
#define SIZE_OF_BLOCK_Y 20

#define OFFSET_X        100
#define OFFSET_Y        100

#define BORDER_WIDTH    1
#define BORDER_COLOR    GetColor(57, 255, 255)

#define W				1	//	白ブロック
#define B				0	//	黒ブロック


int function_status = 0, White, Black;
char KeyBuf[256];
int Mouse = GetMouseInput();
int color;
int mouseX, mouseY;
int title,a;
int masu,back,sikaku,dekasikaku;

WindowArea* Question_Button[12];

void Opening() {
    //DrawString(100, 100, "タイトル画面", White);
    
    //ChangeWindowMode(true);
    DxLib_Init();
       
    //LoadGraphScreen(0, 0, "sozai/title.png", TRUE);
    title = LoadGraph("sozai/title2.png");
    DrawExtendGraph(0, 0, 650, 480, title, FALSE);

    SetFontSize(32); 
    if (KeyBuf[KEY_INPUT_W] == 1) {
        function_status = 1;
    }
    if (GetMouseInput() & MOUSE_INPUT_LEFT) {
        //Question_Button[0] の定義はWinMain
        for (int i = 0; i < 12; i++) {
            if (Question_Button[i]->mouse_in()) {
                function_status = i+1;
            }
        }
    }
}

void Q1() {
   
    back = LoadGraph("sozai/background1.png");
    DrawExtendGraph(0, 0, 1000, 580, back, FALSE);

    sikaku = LoadGraph("sozai/sikaku.png");
    DrawExtendGraph(100, 50, 400, 100, sikaku, TRUE);

    dekasikaku = LoadGraph("sozai/dekasikaku.png");
    DrawExtendGraph(430, 170, 610, 470, dekasikaku, TRUE);

    DrawString(120, 60, "1問目", White);

    if (KeyBuf[KEY_INPUT_SPACE] == 1)
        function_status = 2;

    /*	ゲームブロック	*/
    /*	ネコ　ゲームブロック	*/
    char GameBlocks[NUM_OF_BLOCK_Y + NUM_OF_HINT][NUM_OF_BLOCK_X + NUM_OF_HINT] = {
        {  W , W , W , W , B , W , W , W , W , W , B , W , W , W , W , '1','1',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , B , B , W , W , W , W , B , B , B , W , W , W , '2','2',' ',' ',' ',' ',' ','\n' },
        {  W , W , B , B , B , B , W , W , W , B , B , B , B , W , W , '4','4',' ',' ',' ',' ',' ','\n' },
        {  W , W , B , B , B , B , B , B , B , W , B , B , B , B , W , '4','4',' ',' ',' ',' ',' ','\n' },
        {  W , B , W , W , W , W , W , W , W , W , W , W , W , W , B , '1','3','1',' ',' ',' ',' ','\n' },
        {  B , W , W , W , W , W , W , W , W , W , W , W , W , W , B , '1','1',' ',' ',' ',' ',' ','\n' },
        {  B , W , W , W , B , W , W , W , W , W , B , W , W , W , B , '1','1','1','1',' ',' ',' ','\n' },
        {  B , W , W , W , B , W , W , W , W , W , B , W , W , W , B , '1','1','1','1',' ',' ',' ','\n' },
        {  B , W , W , W , B , W , W , W , W , W , B , W , W , W , B , '1','1','1','1',' ',' ',' ','\n' },
        {  B , W , B , W , W , W , W , B , W , W , W , W , B , W , B , '1','1','1','1',' ',' ',' ','\n' },
        {  W , B , W , W , W , W , W , W , W , W , W , W , W , B , W , '1','1',' ',' ',' ',' ',' ','\n' },
        {  B , W , B , W , B , W , W , B , W , W , B , W , B , W , B , '1','1','1','1','1','1','1','\n' },
        {  W , W , W , B , W , W , B , W , B , W , W , B , W , W , W , '1','1','1','1',' ',' ',' ','\n' },
        {  W , W , B , W , B , W , W , W , W , W , B , W , B , W , W , '1','1','1','1',' ',' ',' ','\n' },
        {  W , B , W , W , W , B , B , B , B , B , W , W , W , B , W , '1','5','1',' ',' ',' ',' ','\n' },
        { '5','1','2','3','4','2','1','1','1','2','4','3','2','1','5','\n'                              },
        { '1','1','1','1','3','1','1','1','1','1','3','1','1','1','1','\n'                              },
        { ' ','1','1',' ','1',' ','1','1','1',' ','1',' ','1','1',' ','\n'                              },
        { ' ',' ','1',' ','1',' ',' ','1',' ',' ','1',' ','1',' ',' ','\n'                              },
    };
    printf("%c", ' ');
    Area* GameDrowing[NUM_OF_BLOCK_Y][NUM_OF_BLOCK_X];
    (new Area(OFFSET_X - BORDER_WIDTH,
        OFFSET_Y - BORDER_WIDTH,
        SIZE_OF_BLOCK_X * NUM_OF_BLOCK_X + BORDER_WIDTH,
        SIZE_OF_BLOCK_Y * NUM_OF_BLOCK_Y + BORDER_WIDTH
    ))->DrawBox(BORDER_COLOR, true);
    for (int y = 0; y < NUM_OF_BLOCK_Y; y++) {
        for (int x = 0; x < NUM_OF_BLOCK_X; x++) {
            GameDrowing[y][x] = new Area(x * SIZE_OF_BLOCK_X + OFFSET_X, y * SIZE_OF_BLOCK_Y + OFFSET_Y, SIZE_OF_BLOCK_X - BORDER_WIDTH, SIZE_OF_BLOCK_Y - BORDER_WIDTH);
            if (GameBlocks[y][x] == B) {
                GameDrowing[y][x]->DrawBox(Black, true);
            }
            else if (GameBlocks[y][x] == W) {			// 白ブロックを表示（削られる前）
                GameDrowing[y][x]->DrawBox(White, true);
            }
        }
    }

    for (int y = 0; y < NUM_OF_BLOCK_Y + NUM_OF_HINT; y++) {
        for (int x = y < NUM_OF_BLOCK_Y ? NUM_OF_BLOCK_X : 0; x < (y < NUM_OF_BLOCK_Y ? NUM_OF_BLOCK_X + NUM_OF_HINT : NUM_OF_BLOCK_X); x++) {
            //std::cout << "DRAW" << GameBlocks[y][x] << "\n";
            DrawString(x * SIZE_OF_BLOCK_X + OFFSET_X, y * SIZE_OF_BLOCK_Y + OFFSET_Y, &GameBlocks[y][x], White);
        }
    }
}

void Q2() {
    DrawExtendGraph(0, 0, 650, 480, masu, FALSE);
    DrawString(120, 40, "2問目", White);
    if (KeyBuf[KEY_INPUT_W] == 1)
        function_status = 3;
}

void Q3() {
    DrawExtendGraph(0, 0, 650, 480, masu, FALSE);
    DrawString(120, 40, "3問目", White);
    if (KeyBuf[KEY_INPUT_SPACE] == 1)
        function_status = 4;
}

void Q4() {
    DrawExtendGraph(0, 0, 650, 480, masu, FALSE);
    DrawString(120, 40, "4問目", White);
    if (KeyBuf[KEY_INPUT_SPACE] == 1)
        function_status = 5;
}

void Q5() {
    DrawExtendGraph(0, 0, 650, 480, masu, FALSE);
    DrawString(120, 40, "5問目", White);
    if (KeyBuf[KEY_INPUT_SPACE] == 1)
        function_status = 6;
}

void Q6() {
    DrawExtendGraph(0, 0, 650, 480, masu, FALSE);
    DrawString(120, 40, "6問目", White);
    if (KeyBuf[KEY_INPUT_SPACE] == 1)
        function_status = 7;
}

void Q7() {
    DrawExtendGraph(0, 0, 650, 480, masu, FALSE);
    DrawString(120, 40, "7問目", White);
    if (KeyBuf[KEY_INPUT_SPACE] == 1)
        function_status = 8;
}

void Q8() {
    DrawExtendGraph(0, 0, 650, 480, masu, FALSE);
    DrawString(120, 40, "8問目", White);
    if (KeyBuf[KEY_INPUT_SPACE] == 1)
        function_status = 9;
}

void Q9() {
    DrawExtendGraph(0, 0, 650, 480, masu, FALSE);
    DrawString(120, 40, "9問目", White);
    if (KeyBuf[KEY_INPUT_SPACE] == 1)
        function_status = 10;
}

void Q10() {
    DrawExtendGraph(0, 0, 650, 480, masu, FALSE);
    DrawString(120, 40, "10問目", White);
    if (KeyBuf[KEY_INPUT_SPACE] == 1)
        function_status = 11;
}

void Q11() {
    DrawExtendGraph(0, 0, 650, 480, masu, FALSE);
    DrawString(120, 40, "11問目", White);
    if (KeyBuf[KEY_INPUT_SPACE] == 1)
        function_status = 12;
}

void Q12() {
    DrawExtendGraph(0, 0, 650, 480, masu, FALSE);
    DrawString(120, 40, "12問目", White);
    if (KeyBuf[KEY_INPUT_SPACE] == 1)
        function_status = 13;
}

void Ending() {
    DrawString(120, 40, "END", White);
    if (KeyBuf[KEY_INPUT_W] == 1)
        function_status = 14;

}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    ChangeWindowMode(TRUE);  
    LPCSTR font_path = "数式フォントver1.5.ttf";        //読み込むフォントファイルのパス
    if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) <= 0) {
        // フォント読込エラー処理
        MessageBox(NULL, "フォント読込失敗", "", MB_OK);
    }
    ChangeFont("数式フォント", DX_CHARSET_DEFAULT);
    if (DxLib_Init() == -1) return -1;                  //ＤＸライブラリ初期化処理 エラーが起きたら終了 

    White = GetColor(255, 255, 255);                    //色の取得
    Black = GetColor(0, 0, 0);                          //色の取得

    SetDrawScreen(DX_SCREEN_BACK);                      //描画先を裏画面に設定
    GetScreenState(&window_x, &window_y, &color);

    Question_Button[0]  = new WindowArea(1.1 / 8, 5.6 / 11, 0.90 / 8, 8.2 / 12 - (5.6 / 11));
    Question_Button[1]  = new WindowArea(2.1 / 8, 5.0 / 11, 3.05 / 8 - (2.1 / 8),  7.6 / 12 - (5.0 / 11));
    Question_Button[2]  = new WindowArea(3.1 / 8, 5.6 / 11, 4.05 / 8 - (3.1 / 8),  8.2 / 12 - (5.6 / 11));
    Question_Button[3]  = new WindowArea(4.1 / 8, 5.0 / 11, 5.05 / 8 - (4.1 / 8),  7.6 / 12 - (5.0 / 11));
    Question_Button[4]  = new WindowArea(5.1 / 8, 5.6 / 11, 6.05 / 8 - (5.1 / 8),  8.2 / 12 - (5.6 / 11));
    Question_Button[5]  = new WindowArea(6.1 / 8, 5.0 / 11, 7.05 / 8 - (6.1 / 8),  7.6 / 12 - (5.0 / 11));
    Question_Button[6]  = new WindowArea(1.1 / 8, 8.5 / 11, 2.00 / 8 - (1.1 / 8), 10.6 / 11 - (8.5 / 11));
    Question_Button[7]  = new WindowArea(2.1 / 8, 7.9 / 11, 3.05 / 8 - (2.1 / 8), 10.0 / 11 - (7.9 / 11));
    Question_Button[8]  = new WindowArea(3.1 / 8, 8.5 / 11, 4.05 / 8 - (3.1 / 8), 10.6 / 11 - (8.5 / 11));
    Question_Button[9]  = new WindowArea(4.1 / 8, 7.9 / 11, 5.05 / 8 - (4.1 / 8), 10.0 / 11 - (7.9 / 11));
    Question_Button[10] = new WindowArea(5.1 / 8, 8.5 / 11, 6.05 / 8 - (5.1 / 8), 10.6 / 11 - (8.5 / 11));
    Question_Button[11] = new WindowArea(6.1 / 8, 7.9 / 11, 7.05 / 8 - (6.1 / 8), 10.0 / 11 - (7.9 / 11));
    while (1) {
        ClearDrawScreen();                              //裏画面のデータを全て削除
        GetHitKeyStateAll(KeyBuf);                      //すべてのキーの状態を得る
        SetMouseDispFlag(TRUE);

        switch (function_status) {
        case 0:
            Opening();
           
            break;
        case 1:
            Q1();
            break;

        case 2:
            Q2();
            break;

        case 3:
            Q3();
            break;
        case 4:
            Q4();
            break;

        case 5:
            Q5();
            break;

        case 6:
            Q6();
            break;

        case 7:
            Q7();
            break;

        case 8:
            Q8();
            break;

        case 9:
            Q9();
            break;

        case 10:
            Q10();
            break;

        case 11:
            Q11();
            break;

        case 12:
            Q12();
            break;

        case 13:
            Ending();
            break;

        default:
            DxLib_End();                                // ＤＸライブラリ使用の終了処理
            return 0;
            break;
        }

        if (ProcessMessage() == -1) break;                 //エラーが起きたら終了

        ScreenFlip();                                   // 裏画面データを表画面へ反映
    }
    if (RemoveFontResourceEx(font_path, FR_PRIVATE, NULL)) {
    }
    else {
        MessageBox(NULL, "remove failure", "", MB_OK);
    }
    DxLib_End();                                            // ＤＸライブラリ使用の終了処理
    return 0;                                               // ソフトの終了
}