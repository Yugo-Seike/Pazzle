#include "DxLib.h"
#include "Area.h"
#include "Questions.h"
//#include <string.h>
//#include <tchar.h>
//#include <iostream>

#define debug_mode 0

#define SIZE_OF_BLOCK_X 45
#define SIZE_OF_BLOCK_Y 45

#define OFFSET_X        300
#define OFFSET_Y        100

#define BORDER_WIDTH    1
#define BORDER_COLOR    GetColor(57, 255, 255)

#define White           GetColor(255, 255, 255)         //�F�̎擾
#define Black           GetColor(0, 0, 0)               //�F�̎擾

#define CHAR_BUF        4


char KeyBuf[256];
int Mouse = GetMouseInput();
int color;
int title,a;
int masu,back,sikaku,dekasikaku,modoru,susumu,clear,failed;
int music[15];



bool is_correct(const char* GameBlocks[NUM_OF_BLOCK_Y + NUM_OF_HINT][NUM_OF_BLOCK_X + NUM_OF_HINT], char BlockStatus[NUM_OF_BLOCK_Y][NUM_OF_BLOCK_X][CHAR_BUF]);
void initPazzle(int qnum, const char* GameBlocks[NUM_OF_BLOCK_Y + NUM_OF_HINT][NUM_OF_BLOCK_X + NUM_OF_HINT]);
int Opening();
int Ending();
void loadFonts(LPCSTR font_path);
void unloadFonts(LPCSTR font_path);
int function_status = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    int qnum = 0, qidx = 0;
    //LPCSTR font_path = "�����t�H���gver1.5.ttf"; 
    LPCSTR font_path = "NagomiGokubosoGothic-ExtraLight.otf"; //�ǂݍ��ރt�H���g�t�@�C���̃p�X
    SetOutApplicationLogValidFlag(debug_mode);
    if (DxLib_Init() == -1) return -1;                  //�c�w���C�u�������������� �G���[���N������I�� 
    SetGraphMode(1280, 1024, 32);
    if (debug_mode) ChangeWindowMode(FALSE);
    else ChangeWindowMode(FALSE);

    loadFonts(font_path);
    ChangeFont("�Ȃ��݋ɍ׃S�V�b�N ExtraLight", DX_CHARSET_DEFAULT);

    music[0] = LoadSoundMem("music/���r�[.mp3");
    music[1] = LoadSoundMem("music/�l�R.mp3");
    music[2] = LoadSoundMem("music/PS.mp3");
    music[3] = LoadSoundMem("music/�C���J.mp3");
    music[4] = LoadSoundMem("music/�J���X.m4a");
    music[5] = LoadSoundMem("music/�P�[�L.mp3");
    music[6] = LoadSoundMem("music/�p���_.mp3");
    music[7] = LoadSoundMem("music/�s�[�X.mp3");
    music[8] = LoadSoundMem("music/�y���M��.mp3");
    music[9] = LoadSoundMem("music/�����S.mp3");
    music[10] = LoadSoundMem("music/�P.mp3");
    music[11] = LoadSoundMem("music/���v.mp3");
    music[12] = LoadSoundMem("music/����.mp3");
    music[13] = LoadSoundMem("music/clear.mp3");
    music[14] = LoadSoundMem("music/failed.mp3");

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
    }
    unloadFonts(font_path);                                 //�t�H���g�̃A�����[�h
    
    DxLib_End();                                            // �c�w���C�u�����g�p�̏I������
    return 0;                                               // �\�t�g�̏I��
}

void initPazzle(int qnum, const char* GameBlocks[NUM_OF_BLOCK_Y + NUM_OF_HINT][NUM_OF_BLOCK_X + NUM_OF_HINT]) {
    char qnum_str[8] = "";
    
    StopSoundMem(music[0]);
    

    PlaySoundMem(music[qnum], DX_PLAYTYPE_LOOP);

    if (debug_mode) printfDx("called!");
    back = LoadGraph("sozai/background1.png");
    DrawExtendGraph(0, 0, window_x, window_y, back, FALSE);

    sikaku = LoadGraph("sozai/sikaku.png");
    DrawExtendGraph(300, 30, 970, 200, sikaku, TRUE);

    //dekasikaku = LoadGraph("sozai/dekasikaku.png");
    //DrawExtendGraph(430, 170, 610, 470, dekasikaku, TRUE);

    //sprintf_s(qnum_str, "%d%s", qnum, "���");

    //DrawString(120, 60, qnum_str, White);

    Area* modomodo = new Area(10, 850, 240, 150);
    modoru = LoadGraph("sozai/�߂�{�^��.png");
    modomodo->DrawExtendGraph(modoru);
    //DrawExtendGraph(10, 850, 250, 1000, modoru, TRUE);

    Area* susumuzo = new Area(1000, 830, 240, 170);
    susumu = LoadGraph("sozai/����.png");
    susumuzo->DrawExtendGraph(susumu);
    //DrawExtendGraph(1000, 830, 1240, 1000, susumu, TRUE);
    

    SetFontSize(34);
    DrawString(300, 40, Question_name[qnum-1], White);
    SetFontSize(28);

    Area* GameDrowing[NUM_OF_BLOCK_Y][NUM_OF_BLOCK_X];
    char BlockStatus[NUM_OF_BLOCK_Y][NUM_OF_BLOCK_X][CHAR_BUF];
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
            strcpy_s(BlockStatus[y][x], sizeof(BlockStatus[y][x]), W);
            if (debug_mode) {
                //�f�o�b�O���[�h�ł͉𓚂�\��
                strcpy_s(BlockStatus[y][x], sizeof(BlockStatus[y][x]), GameBlocks[y][x]);
                if (strcmp(GameBlocks[y][x], W) == 0) GameDrowing[y][x]->DrawBox(White, true);
                if (strcmp(GameBlocks[y][x], B) == 0) GameDrowing[y][x]->DrawBox(Black, true);
            }
        }
    }

    //�q���g�̕\��
    for (int y = 0; y < NUM_OF_BLOCK_Y + NUM_OF_HINT; y++) {
        for (int x = y < NUM_OF_BLOCK_Y ? NUM_OF_BLOCK_X : 0; x < (y < NUM_OF_BLOCK_Y ? NUM_OF_BLOCK_X + NUM_OF_HINT : NUM_OF_BLOCK_X); x++) {
            if (GameBlocks[y][x] != nullptr && strcmp(GameBlocks[y][x], " ") != 0) {
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
                        if (strcmp(blockmode, BLANK) == 0) {
                            //���N���b�N�F���������~������
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
                            //�E�N���b�N�F�����~������
                            if (GetMouseInput() & MOUSE_INPUT_RIGHT){
                                if (strcmp(BlockStatus[y][x], X) == 0) {
                                    strcpy_s(blockmode, sizeof(blockmode), W);
                                }
                                else {
                                    strcpy_s(blockmode, sizeof(blockmode), X);
                                }
                            }
                        }
                        GameDrowing[y][x]->DrawBox(strcmp(blockmode, B) == 0 ? Black : White, true);
                        if (strcmp(blockmode, X) == 0) GameDrowing[y][x]->DrawX(Black);
                        strcpy_s(BlockStatus[y][x], sizeof(BlockStatus[y][x]), blockmode);
                        ScreenFlip();
                    }
                }
            }
            if (modomodo->mouse_in()) {
                StopSoundMem(music[qnum]);
                function_status = 0;
                return;
            }
            if (susumuzo->mouse_in()) { //TODO: �������킹�̃{�^����������
                StopSoundMem(music[qnum]);
                if (is_correct(GameBlocks, BlockStatus)) {
                    PlaySoundMem(music[13], DX_PLAYTYPE_BACK);
                    function_status = 13;
                    return;
                }
                else {
                    //TODO: �ԈႢ�̏ꍇ�̏����i���ēx���͑҂��Ɂj
                    //if (debug_mode) printfDx("incorrect!");
                    PlaySoundMem(music[14], DX_PLAYTYPE_LOOP);
                    back = LoadGraph("sozai/background1.png");
                    DrawExtendGraph(0, 0, window_x, window_y, back, FALSE);

                    failed = LoadGraph("sozai/Failed.png");
                    DrawExtendGraph(0, 0, window_x, window_y, failed, TRUE);

                    ScreenFlip();
                    WaitKey();

                    StopSoundMem(music[14]);
                    PlaySoundMem(music[qnum], DX_PLAYTYPE_LOOP);

                    if ((new WindowArea(0, 9.0 / 11, 1, 1.0 / 11))->mouse_in()) {
                        StopSoundMem(music[qnum]);
                        function_status = 0;
                        return;
                    }

                    DrawExtendGraph(0, 0, window_x, window_y, back, FALSE);
                    DrawExtendGraph(300, 30, 970, 200, sikaku, TRUE);
                    modomodo->DrawExtendGraph(modoru);
                    susumuzo->DrawExtendGraph(susumu);

                    SetFontSize(34);
                    DrawString(300, 40, Question_name[qnum - 1], White);
                    SetFontSize(28);

                    //�u���b�N�̏�ԕ���
                    for (int y = 0; y < NUM_OF_BLOCK_Y; y++) {
                        for (int x = 0; x < NUM_OF_BLOCK_X; x++) {
                            GameDrowing[y][x]->DrawBox(strcmp(BlockStatus[y][x], B) == 0 ? Black : White, true);
                            if (strcmp(BlockStatus[y][x], X) == 0) GameDrowing[y][x]->DrawX(Black);
                        }
                    }
                    //�q���g�̕\��
                    for (int y = 0; y < NUM_OF_BLOCK_Y + 4; y++) {
                        for (int x = y < NUM_OF_BLOCK_Y ? NUM_OF_BLOCK_X : 0; x < (y < NUM_OF_BLOCK_Y ? NUM_OF_BLOCK_X + NUM_OF_HINT : NUM_OF_BLOCK_X); x++) {
                            if (GameBlocks[y][x] != nullptr && strcmp(GameBlocks[y][x], " ") != 0) {
                                DrawString(x * SIZE_OF_BLOCK_X + OFFSET_X, y * SIZE_OF_BLOCK_Y + OFFSET_Y, GameBlocks[y][x], White);
                            }
                        }
                    }
                }
            }
        }
    }

    if (debug_mode) printfDx("correct!");
    //TODO: ������ʁ����j���[�֖߂鏈��

}

int Opening() {
    int rtn = 0;
    //DrawString(100, 100, "�^�C�g�����", White);

    //ChangeWindowMode(true);

    //LoadGraphScreen(0, 0, "sozai/title.png", TRUE);
    StopSoundMem(music[13]);
    StopSoundMem(music[14]);

    title = LoadGraph("sozai/title2.png");
    DrawExtendGraph(0, 0, window_x, window_y, title, FALSE);
    PlaySoundMem(music[0], DX_PLAYTYPE_LOOP);
    
    //if (KeyBuf[KEY_INPUT_W] == 1) {
    //    return 1;
    //}
    if (debug_mode) {
        for (int i = 0; i < NUM_OF_QUESTION; i++) {
            Question_Button[i]->DrawBox(White, false);
        }
    }
    ScreenFlip();
    while (!rtn) {
        WaitKey();
        if (GetMouseInput() & MOUSE_INPUT_LEFT) {
            for (int i = 0; i < NUM_OF_QUESTION; i++) {
                if (Question_Button[i]->mouse_in()) {
                    rtn = i + 1;
                }
            }
        }
    }
    return rtn;
}

int Ending() {
    back = LoadGraph("sozai/background1.png");
    DrawExtendGraph(0, 0, window_x, window_y, back, FALSE);

    clear = LoadGraph("sozai/Clear.png");
    DrawExtendGraph(0, 0, window_x, window_y, clear, TRUE);

    ScreenFlip();
    WaitKey();
    if (KeyBuf[KEY_INPUT_W] == 1) return 14;
}

void loadFonts(LPCSTR font_path) {
    // �t�H���g�Ǎ��G���[����
    if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) <= 0) MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
}

void unloadFonts(LPCSTR font_path) {
    if (!RemoveFontResourceEx(font_path, FR_PRIVATE, NULL)) MessageBox(NULL, "remove failure", "", MB_OK);
}

bool is_correct(const char *GameBlocks[NUM_OF_BLOCK_Y + NUM_OF_HINT][NUM_OF_BLOCK_X + NUM_OF_HINT], char BlockStatus[NUM_OF_BLOCK_Y][NUM_OF_BLOCK_X][CHAR_BUF]) {
    bool rtn = true;
    for (int x = 0; x < NUM_OF_BLOCK_X; x++) {
        for (int y = 0; y < NUM_OF_BLOCK_X; y++) {
            rtn &= (strcmp(BlockStatus[y][x], GameBlocks[y][x]) == 0) || (strcmp(BlockStatus[y][x], X) == 0 && strcmp(GameBlocks[y][x], W) == 0);
        }
    }
    return rtn;
}