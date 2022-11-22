#include "DxLib.h"
#include "Area.h"

#define NUM_OF_BLOCK_X	15
#define NUM_OF_BLOCK_Y	15
#define NUM_OF_HINT		8

#define W				1	//	白ブロック

int function_status = 0, White;
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

    /*
    DrawBox((window_x / 8 * 1.1), (window_y / 11) * 5.6, (window_x / 8) * 2, (window_y / 12) * 8.2, GetColor(200, 0, 0), false);  //1
    DrawBox((window_x / 8 * 2.1), (window_y / 11) * 5, (window_x / 8) * 3.05, (window_y / 12) * 7.6, GetColor(0, 200, 0), false);  //2
    DrawBox((window_x / 8 * 3.1), (window_y / 11) * 5.6, (window_x / 8) * 4.05, (window_y / 12) * 8.2, GetColor(0, 0, 200), false);  //3
    DrawBox((window_x / 8 * 4.1), (window_y / 11) * 5, (window_x / 8) * 5.05, (window_y / 12) * 7.6, GetColor(0, 200, 0), false);  //4
    DrawBox((window_x / 8 * 5.1), (window_y / 11) * 5.6, (window_x / 8) * 6.05, (window_y / 12) * 8.2, GetColor(0, 0, 200), false);  //5
    DrawBox((window_x / 8 * 6.1), (window_y / 11) * 5, (window_x / 8) * 7.05, (window_y / 12) * 7.6, GetColor(0, 200, 0), false);  //6

    DrawBox((window_x / 8 * 1.1), (window_y / 11) * 8.5, (window_x / 8) * 2, (window_y / 11) * 10.6, GetColor(200, 0, 0), false);  //7
    DrawBox((window_x / 8 * 2.1), (window_y / 11) * 7.9, (window_x / 8) * 3.05, (window_y / 11) * 10, GetColor(200, 0, 0), false);  //8
    DrawBox((window_x / 8 * 3.1), (window_y / 11) * 8.5, (window_x / 8) * 4.05, (window_y / 11) * 10.6, GetColor(200, 0, 0), false);  //9
    DrawBox((window_x / 8 * 4.1), (window_y / 11) * 7.9, (window_x / 8) * 5.05, (window_y / 11) * 10, GetColor(200, 0, 0), false);  //10
    DrawBox((window_x / 8 * 5.1), (window_y / 11) * 8.5, (window_x / 8) * 6.05, (window_y / 11) * 10.6, GetColor(200, 0, 0), false);  //11
    DrawBox((window_x / 8 * 6.1), (window_y / 11) * 7.9, (window_x / 8) * 7.05, (window_y / 11) * 10, GetColor(200, 0, 0), false);  //12
    */

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

    masu = LoadGraph("sozai/masu.png");
    DrawExtendGraph(100, 170, 400, 470, masu, TRUE);

    dekasikaku = LoadGraph("sozai/dekasikaku.png");
    DrawExtendGraph(430, 170, 610, 470, dekasikaku, TRUE);

    DrawString(120, 60, "1問目", White);

    if (KeyBuf[KEY_INPUT_SPACE] == 1)
        function_status = 2;

    /*	ゲームブロック	*/
    char GameBlocks[NUM_OF_BLOCK_Y + NUM_OF_HINT][NUM_OF_BLOCK_X + NUM_OF_HINT] = {
        {  W , W , W , W , W , W , W , W , W , W , W , W , W , W , W , '0',' ',' ',' ','\n'	},
        {  W , W , W , W , W , W , W , W , W , W , W , W , W , W , W , '2','2',' ',' ','\n'	},
        {  W , W , W , W , W , W , W , W , W , W , W , W , W , W , W , '1','1','1','1','\n'	},
        {  W , W , W , W , W , W , W , W , W , W , W , W , W , W , W , '1','1',' ',' ','\n'	},
        {  W , W , W , W , W , W , W , W , W , W , W , W , W , W , W , '1','1',' ',' ','\n'	},
        {  W , W , W , W , W , W , W , W , W , W , W , W , W , W , W , '4','4',' ',' ','\n'	},
        {  W , W , W , W , W , W , W , W , W , W , W , W , W , W , W , '1','1','1','1','\n'	},
        {  W , W , W , W , W , W , W , W , W , W , W , W , W , W , W , '1','4','1',' ','\n'	},
        {  W , W , W , W , W , W , W , W , W , W , W , W , W , W , W , '1','1','1','1','\n'	},
        {  W , W , W , W , W , W , W , W , W , W , W , W , W , W , W , '3','3',' ',' ','\n'	},
        {  W , W , W , W , W , W , W , W , W , W , W , W , W , W , W , '3','3',' ',' ','\n'	},
        {  W , W , W , W , W , W , W , W , W , W , W , W , W , W , W , '3','3',' ',' ','\n'	},
        {  W , W , W , W , W , W , W , W , W , W , W , W , W , W , W , '3','3',' ',' ','\n'	},
        {  W , W , W , W , W , W , W , W , W , W , W , W , W , W , W , '3','3',' ',' ','\n'	},
        {  W , W , W , W , W , W , W , W , W , W , W , W , W , W , W , '3','3',' ',' ','\n'	},
        { '7','1','1','1','1','1','1','1','1','7','7','1','1','1','1','\n'					},
        { ' ','1','1','5',' ',' ','5','1','1',' ','7','1','1','1','1','\n'					},
        { ' ','1','1',' ',' ',' ',' ','1','1',' ','7','1','1','1','1','\n'					},
    };
    printf("%c", ' ');

    for (int y = 0; y < 18; y++) {
        for (int x = 0; x < 20; x++) {

            if (GameBlocks[y][x] == 0) {
                break;
            }
            else if (GameBlocks[y][x] == W) {			// 白ブロックを表示（削られる前）
                DrawString(x, y, "■", White);
            }
            else {
                printf("%c%c", GameBlocks[y][x], ' ');	// ヒントを表示
            }
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
    ChangeWindowMode(FALSE);  
    LPCSTR font_path = "数式フォントver1.5.ttf";        //読み込むフォントファイルのパス
    if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) <= 0) {
        // フォント読込エラー処理
        MessageBox(NULL, "フォント読込失敗", "", MB_OK);
    }
    ChangeFont("数式フォント", DX_CHARSET_DEFAULT);
    if (DxLib_Init() == -1) return -1;                  //ＤＸライブラリ初期化処理 エラーが起きたら終了 

    White = GetColor(255, 255, 255);                    //色の取得

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