#include "DxLib.h"

int function_status = 0, White;
char KeyBuf[256];
int Mouse = GetMouseInput();
int window_x, window_y, color;
int mouseX, mouseY;
int title,a;
int masu;



void Opening() {
    //DrawString(100, 100, "タイトル画面", White);
    
        //ChangeWindowMode(true);
        DxLib_Init();
        int window_x, window_y, color;
        GetScreenState(&window_x, &window_y, &color);
       
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
            GetMousePoint(&mouseX, &mouseY);
            //上段
            //1
            if ((mouseY >= (window_y / 11) * 5.6) && (mouseY <= (window_y / 12) * 8.2)) {
                if ((mouseX >= (window_x / 8 * 1.1)) && (mouseX <= (window_x / 8) * 2)) {
                    function_status = 1;
                }
            }
            //2
            if ((mouseY >= (window_y / 11) * 5) && (mouseY <= (window_y / 12) * 7.6)) {
                if ((mouseX >= (window_x / 8 * 2.1)) && (mouseX <= (window_x / 8) * 3.05)) {
                    function_status = 2;
                }
            }
            //3
            if ((mouseY >= (window_y / 11) * 5.6) && (mouseY <= (window_y / 12) * 8.2)) {
                if ((mouseX >= (window_x / 8 * 3.1)) && (mouseX <= (window_x / 8) * 4.05)) {
                    function_status = 3;
                }
            }
            //4
            if ((mouseY >= (window_y / 11) * 5) && (mouseY <= (window_y / 12) * 7.6)) {
                if ((mouseX >= (window_x / 8 * 4.1)) && (mouseX <= (window_x / 8) * 5.05)) {
                    function_status = 4;
                }
            }
            //5
            if ((mouseY >= (window_y / 11) * 5.6) && (mouseY <= (window_y / 12) * 8.2)) {
                if ((mouseX >= (window_x / 8 * 5.1)) && (mouseX <= (window_x / 8) * 6.05)) {
                    function_status = 5;
                }
            }
            //6
            if ((mouseY >= (window_y / 11) * 5) && (mouseY <= (window_y / 12) * 7.6)) {
                if ((mouseX >= (window_x / 8 * 6.1)) && (mouseX <= (window_x / 8) * 7.05)) {
                    function_status = 6;
                }
            }
            //下段
            //7
            if ((mouseY >= (window_y / 11) * 8.5) && (mouseY <= (window_y / 11) * 10.6)) {
                if ((mouseX >= (window_x / 8 * 1.1)) && (mouseX <= (window_x / 8) * 2)) {
                    function_status = 7;
                }
            }
            //8
            if ((mouseY >= (window_y / 11) * 7.9) && (mouseY <= (window_y / 11) * 10)) {
                if ((mouseX >= (window_x / 8 * 2.1)) && (mouseX <= (window_x / 8) * 3.05)) {
                    function_status = 8;
                }
            }
            //9
            if ((mouseY >= (window_y / 11) * 8.5) && (mouseY <= (window_y / 11) * 10.6)) {
                if ((mouseX >= (window_x / 8 * 3.1)) && (mouseX <= (window_x / 8) * 4.05)) {
                    function_status = 9;
                }
            }
            //10
            if ((mouseY >= (window_y / 11) * 7.9) && (mouseY <= (window_y / 11) * 10)) {
                if ((mouseX >= (window_x / 8 * 4.1)) && (mouseX <= (window_x / 8) * 5.05)) {
                    function_status = 10;
                }
            }
            //11
            if ((mouseY >= (window_y / 11) * 8.5) && (mouseY <= (window_y / 11) * 10.6)) {
                if ((mouseX >= (window_x / 8 * 5.1)) && (mouseX <= (window_x / 8) * 6.05)) {
                    function_status = 11;
                }
            }
            //12
            if ((mouseY >= (window_y / 11) * 7.9) && (mouseY <= (window_y / 11) * 10)) {
                if ((mouseX >= (window_x / 8 * 6.1)) && (mouseX <= (window_x / 8) * 7.05)) {
                    function_status = 12;
                }
            }
        }
        
      
}

void Q1() {
    int back;

    masu = LoadGraph("sozai/puzzle2.png");
    DrawExtendGraph(0, 0, 650, 480, masu, FALSE);

    DrawString(120, 40, "1問目", White);

    if (KeyBuf[KEY_INPUT_SPACE] == 1)
        function_status = 2;

    if (KeyBuf[KEY_INPUT_S] == 1)
        function_status = 0;
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
    if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
    }
    else {
        // フォント読込エラー処理
        MessageBox(NULL, "フォント読込失敗", "", MB_OK);
    }
    ChangeFont("数式フォント", DX_CHARSET_DEFAULT);
    if (DxLib_Init() == -1) return -1;                  //ＤＸライブラリ初期化処理 エラーが起きたら終了 

    White = GetColor(255, 255, 255);                    //色の取得

    SetDrawScreen(DX_SCREEN_BACK);                      //描画先を裏画面に設定

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