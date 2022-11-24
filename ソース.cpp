#include "DxLib.h"
#include "Area.h"
#include "Questions.h"
//#include <tchar.h>
//#include <iostream>

#define debug_mode 0

#define SIZE_OF_BLOCK_X 20
#define SIZE_OF_BLOCK_Y 20

#define OFFSET_X        150
#define OFFSET_Y        80

#define BORDER_WIDTH    1
#define BORDER_COLOR    GetColor(57, 255, 255)

#define White           GetColor(255, 255, 255)         //�F�̎擾
#define Black           GetColor(0, 0, 0)               //�F�̎擾


char KeyBuf[256];
int Mouse = GetMouseInput();
int color;
int title,a;
int masu,back,sikaku,dekasikaku,modoru;



bool is_correct(char GameBlocks[NUM_OF_BLOCK_Y + NUM_OF_HINT][NUM_OF_BLOCK_X + NUM_OF_HINT], char BlockStatus[NUM_OF_BLOCK_Y][NUM_OF_BLOCK_X]);
void initPazzle(int qnum, char GameBlocks[NUM_OF_BLOCK_Y + NUM_OF_HINT][NUM_OF_BLOCK_X + NUM_OF_HINT]);
int Opening();
int Ending();
void loadFonts(LPCSTR font_path);
void unloadFonts(LPCSTR font_path);
int function_status = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    int qnum = 0, qidx = 0;
    //LPCSTR font_path = "�����t�H���gver1.5.ttf"; 
    LPCSTR font_path = "NagomiGokubosoGothic-ExtraLight.otf"; //�ǂݍ��ރt�H���g�t�@�C���̃p�X
    ChangeWindowMode(TRUE);  
    if (DxLib_Init() == -1) return -1;                  //�c�w���C�u�������������� �G���[���N������I�� 

    loadFonts(font_path);
    ChangeFont("�Ȃ��݋ɍ׃S�V�b�N ExtraLight", DX_CHARSET_DEFAULT);
    SetDrawScreen(DX_SCREEN_BACK);                      //�`���𗠉�ʂɐݒ�
    GetScreenState(&window_x, &window_y, &color);
    setPositions();

    while (1) {
        ClearDrawScreen();                              //����ʂ̃f�[�^��S�č폜
        GetHitKeyStateAll(KeyBuf);                      //���ׂẴL�[�̏�Ԃ𓾂�
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

                if (KeyBuf[KEY_INPUT_SPACE] == 1) function_status++;    //�Ȃ�̂��߂ɂ��Ă���̂��킩��Ȃ�
                break;

            case 13:
                function_status = Ending();
                break;

            default:
                DxLib_End();                                // �c�w���C�u�����g�p�̏I������
                return 0;
                break;
        }

        if (ProcessMessage() == -1) break;                  //�G���[���N������I��

        ScreenFlip();                                       // ����ʃf�[�^��\��ʂ֔��f
        WaitKey();
    }
    unloadFonts(font_path);                                 //�t�H���g�̃A�����[�h
    
    DxLib_End();                                            // �c�w���C�u�����g�p�̏I������
    return 0;                                               // �\�t�g�̏I��
}

void initPazzle(int qnum, char GameBlocks[NUM_OF_BLOCK_Y + NUM_OF_HINT][NUM_OF_BLOCK_X + NUM_OF_HINT]) {
    char qnum_str[8] = "";
    if (debug_mode) printfDx("called!");
    back = LoadGraph("sozai/background1.png");
    DrawExtendGraph(0, 0, 1000, 580, back, FALSE);

    sikaku = LoadGraph("sozai/sikaku.png");
    DrawExtendGraph(150, 30, 450, 80, sikaku, TRUE);

    //dekasikaku = LoadGraph("sozai/dekasikaku.png");
    //DrawExtendGraph(430, 170, 610, 470, dekasikaku, TRUE);

    //sprintf_s(qnum_str, "%d%s", qnum, "���");

    //DrawString(120, 60, qnum_str, White);

    modoru = LoadGraph("sozai/�߂�{�^��.png");
    DrawExtendGraph(10, 400, 150, 480, modoru, TRUE);
    Area* modomodo = new Area(10, 400, 150, 480);
    

    SetFontSize(32);
    DrawString(150, 40, Question_name[qnum-1], White);
    SetFontSize(25);

    Area* GameDrowing[NUM_OF_BLOCK_Y][NUM_OF_BLOCK_X];
    char BlockStatus[NUM_OF_BLOCK_Y][NUM_OF_BLOCK_X];
    (new Area(OFFSET_X - BORDER_WIDTH,
        OFFSET_Y - BORDER_WIDTH,
        SIZE_OF_BLOCK_X * NUM_OF_BLOCK_X + BORDER_WIDTH,
        SIZE_OF_BLOCK_Y * NUM_OF_BLOCK_Y + BORDER_WIDTH
    ))->DrawBox(BORDER_COLOR, true);

    //�e�u���b�N���쐬
    for (int y = 0; y < NUM_OF_BLOCK_Y; y++) {
        for (int x = 0; x < NUM_OF_BLOCK_X; x++) {
            GameDrowing[y][x] = new Area(x * SIZE_OF_BLOCK_X + OFFSET_X, y * SIZE_OF_BLOCK_Y + OFFSET_Y, SIZE_OF_BLOCK_X - BORDER_WIDTH, SIZE_OF_BLOCK_Y - BORDER_WIDTH);
            GameDrowing[y][x]->DrawBox(White, true);
            BlockStatus[y][x] = W;
            if (debug_mode) {
                //�f�o�b�O���[�h�ł͉𓚂�\��
                BlockStatus[y][x] = GameBlocks[y][x];
                if (GameBlocks[y][x] == W) GameDrowing[y][x]->DrawBox(White, true);
                if (GameBlocks[y][x] == B) GameDrowing[y][x]->DrawBox(Black, true);
            }
        }
    }

    //�q���g�̕\��
    for (int y = 0; y < NUM_OF_BLOCK_Y + 4; y++) {
        for (int x = y < NUM_OF_BLOCK_Y ? NUM_OF_BLOCK_X : 0; x < (y < NUM_OF_BLOCK_Y ? NUM_OF_BLOCK_X + NUM_OF_HINT : NUM_OF_BLOCK_X); x++) {
            if (GameBlocks[y][x] != ' ') {
                char str[] = { GameBlocks[y][x], '\0'}; //�����o���p�̃������̈���쐬�i�e�����̌���null�������̈���쐬�j
                DrawString(x * SIZE_OF_BLOCK_X + OFFSET_X, y * SIZE_OF_BLOCK_Y + OFFSET_Y, str, White); //str�̐擪�A�h���X��n��
            }
        }
    }

    while (1) {
        ScreenFlip();
        WaitKey();
        if (GetMouseInput() & MOUSE_INPUT_LEFT) {
            if (modomodo->mouse_in()) {
                function_status = Opening();
            }
            for (int y = 0; y < NUM_OF_BLOCK_Y; y++) {
                for (int x = 0; x < NUM_OF_BLOCK_X; x++) {
                    if (GameDrowing[y][x]->mouse_in()) {
                        if (BlockStatus[y][x] == W) {
                            GameDrowing[y][x]->DrawBox(Black, true);
                            BlockStatus[y][x] = B;
                        }
                        else {
                            GameDrowing[y][x]->DrawBox(White, true);
                            BlockStatus[y][x] = W;
                        }
                    }
                }
            }
        }
        if (false) { //TODO: �������킹�̃{�^����������
            if (is_correct(GameBlocks, BlockStatus)) {
                break;
            }
            else {
                //TODO: �ԈႢ�̏ꍇ�̏����i���ēx���͑҂��Ɂj
                if (debug_mode) printfDx("incorrect!");
            }
        }
    }

    if (debug_mode) printfDx("correct!");
    //TODO: ������ʁ����j���[�֖߂鏈��

}

int Opening() {
    //DrawString(100, 100, "�^�C�g�����", White);

    //ChangeWindowMode(true);
    DxLib_Init();

    //LoadGraphScreen(0, 0, "sozai/title.png", TRUE);
    title = LoadGraph("sozai/title2.png");
    DrawExtendGraph(0, 0, 650, 480, title, FALSE);

    
    if (KeyBuf[KEY_INPUT_W] == 1) {
        return 1;
    }
    if (debug_mode) {
        for (int i = 0; i < NUM_OF_QUESTION; i++) {
            Question_Button[i]->DrawBox(White, false);
        }
    }
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
    // �t�H���g�Ǎ��G���[����
    if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) <= 0) MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
}

void unloadFonts(LPCSTR font_path) {
    if (!RemoveFontResourceEx(font_path, FR_PRIVATE, NULL)) MessageBox(NULL, "remove failure", "", MB_OK);
}

bool is_correct(char GameBlocks[NUM_OF_BLOCK_Y + NUM_OF_HINT][NUM_OF_BLOCK_X + NUM_OF_HINT], char BlockStatus[NUM_OF_BLOCK_Y][NUM_OF_BLOCK_X]) {
    bool rtn = true;
    for (int x = 0; x < NUM_OF_BLOCK_X; x++) {
        for (int y = 0; y < NUM_OF_BLOCK_X; y++) {
            rtn &= GameBlocks[y][x] == BlockStatus[y][x];
        }
    }
    return rtn;
}
