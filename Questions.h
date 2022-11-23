#pragma once
#include "Area.h"

#define NUM_OF_BLOCK_X	15
#define NUM_OF_BLOCK_Y	15

#define NUM_OF_QUESTION 12
#define NUM_OF_HINT		8

#define W				1	//	白ブロック
#define B				0	//	黒ブロック

WindowArea* Question_Button[NUM_OF_QUESTION];

char GameBlocks[NUM_OF_QUESTION][NUM_OF_BLOCK_Y + NUM_OF_HINT][NUM_OF_BLOCK_X + NUM_OF_HINT] = {
    /*  Q1 ネコ   */
    {
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
    },


    /*  PSマーク  */
    {
        {  W , W , W , W , W , W , B , W , W , W , W , W , W , W , W , '1',' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , B , B , W , W , W , W , W , W , W , '2',' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , B , B , B , W , W , W , W , W , W , '3',' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , B , B , B , B , B , W , W , W , W , '5',' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , B , B , W , B , B , B , W , W , W , '2','3',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , B , W , B , B , W , B , B , W , W , W , W , '2','2','2',' ',' ',' ',' ','\n' },
        {  W , W , W , B , B , W , B , B , W , B , W , W , W , W , W , '2','2','1',' ',' ',' ',' ','\n' },
        {  W , W , B , B , B , W , B , B , W , W , W , W , B , W , W , '3','2','1',' ',' ',' ',' ','\n' },
        {  W , B , B , B , W , W , B , B , W , B , B , B , B , B , W , '3','2','5',' ',' ',' ',' ','\n' },
        {  B , B , B , W , W , W , B , B , B , B , B , B , B , B , B , '3','9',' ',' ',' ',' ',' ','\n' },
        {  B , B , W , W , B , B , B , B , B , B , W , W , B , B , B , '2','6','3',' ',' ',' ',' ','\n' },
        {  B , W , W , B , B , B , B , B , B , W , W , W , B , B , B , '1','6','3',' ',' ',' ',' ','\n' },
        {  B , B , B , B , B , W , B , B , W , W , W , B , B , B , W , '5','2','3',' ',' ',' ',' ','\n' },
        {  B , B , B , B , W , W , B , B , W , W , B , B , B , W , W , '4','2','3',' ',' ',' ',' ','\n' },
        {  W , B , B , W , W , W , W , B , W , B , B , B , W , W , W , '2','1','3',' ',' ',' ',' ','\n' },
        { '5','3','3','3','3','2','14','14','2','4','3','1','7','5','3','\n'			                },
        { ' ','3','3','3','3',' ',' ',' ','3','3','2','2',' ',' ',' ','\n'					            },
        { ' ',' ',' ',' ',' ',' ',' ',' ',' ','1','2','3',' ',' ',' ','\n'					            },
        { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\n'					            },
    },

    /*  イルカ  */
    {
        {  W , W , W , W , W , W , W , W , W , W , W , W , W , W , W , ' ' ,' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , B , B , B , B , B , W , W , B , B , B , '5' ,'3',' ',' ',' ',' ',' ','\n' },
        {  W , W , B , B , B , B , B , B , B , B , B , B , B , B , B , '13',' ',' ',' ',' ',' ',' ','\n' },
        {  W , B , B , B , B , B , B , B , B , B , B , B , B , B , W , '13',' ',' ',' ',' ',' ',' ','\n' },
        {  W , B , B , B , B , B , B , B , B , B , B , B , B , W , W , '12',' ',' ',' ',' ',' ',' ','\n' },
        {  W , B , B , B , B , B , B , B , B , B , B , B , B , W , W , '12',' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , B , B , B , B , B , B , B , B , B , B , B , B , W , '12',' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , B , B , B , B , B , B , B , B , B , W , '9' ,' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , B , B , B , B , B , B , B , B , B , B , '10',' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , B , B , B , B , B , B , B , B , B , B , '10',' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , B , B , B , W , W , B , B , B , B , W , '3' ,'4',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , B , B , W , W , W , B , B , B , W , '2' ,'3',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , W , W , W , W , B , B , B , B , W , '4' ,' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , W , W , W , W , B , B , B , B , B , '5' ,' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , W , W , W , W , W , W , B , B , B , '3' ,' ',' ',' ',' ',' ',' ','\n' },
        { ' ','3','5','5','5','10','11','11','9','9','9','12','14','3','2','\n'			                 },
        { ' ',' ',' ',' ',' ',' ' ,' ' ,' ' ,' ',' ','2',' ' ,' ' ,'9','2','\n'					         },
        { ' ',' ',' ',' ',' ',' ' ,' ' ,' ' ,' ',' ',' ',' ' ,' ' ,' ','2','\n'					         },
        { ' ',' ',' ',' ',' ',' ' ,' ' ,' ' ,' ',' ',' ',' ' ,' ' ,' ',' ','\n'			                 },
    },
    /*  カラス  */
    {
        {  W , W , W , B , B , B , W , W , W , W , W , W , W , W , W , '3' ,' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , B , B , W , B , B , W , W , W , W , W , W , W , W , '2' ,'2',' ',' ',' ',' ',' ','\n' },
        {  B , B , B , B , B , B , B , W , W , W , W , W , W , W , W , '7' ,' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , B , B , B , B , B , W , W , W , W , W , W , W , '5' ,' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , B , B , B , B , B , B , W , W , W , W , W , W , '6' ,' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , B , B , B , B , B , B , B , B , W , W , W , W , W , '8' ,' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , B , B , B , B , B , B , B , B , B , W , W , W , W , '9' ,' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , B , B , B , B , B , B , B , B , B , B , W , W , W , '10',' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , B , B , B , B , B , B , B , B , B , B , W , W , '10',' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , B , B , B , B , B , B , B , B , B , W , W , '9' ,' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , B , W , B , B , B , B , B , B , B , W , '1' ,'7',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , B , W , W , B , B , B , B , B , B , B , '1' ,'1','3',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , B , W , W , W , B , W , W , W , B , B , '1' ,'1','2',' ',' ',' ',' ','\n' },
        {  W , W , W , W , B , B , W , W , W , B , W , W , W , W , W , '2' ,'1',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , W , W , B , B , W , W , W , W , W , '2' ,' ',' ',' ',' ',' ',' ','\n' },
        { '1','1','2','9','1','14','9','8','11','6','5','4','4','3','2','\n'			                 },
        { ' ',' ','3',' ','8',' ' ,' ',' ',' ' ,' ',' ',' ',' ',' ',' ','\n'					         },
        { ' ',' ',' ',' ',' ',' ' ,' ',' ',' ' ,' ',' ',' ',' ',' ',' ','\n'					         },
        { ' ',' ',' ',' ',' ',' ' ,' ',' ',' ' ,' ',' ',' ',' ',' ',' ','\n'					         },
    },
    /*  ケーキ  */
    {
        {  W , W , W , W , W , W , W , W , W , W , B , W , W , W , W , '1',' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , W , W , W , B , W , B , W , W , W , '1','1',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , W , W , B , W , W , W , B , B , B , '1','3',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , B , B , B , B , B , B , W , W , W , B , W , B , '6','1','1',' ',' ',' ',' ','\n' },
        {  B , B , B , W , W , W , W , W , B , W , W , B , W , W , B , '3','1','1','1',' ',' ',' ','\n' },
        {  B , B , W , W , W , W , W , W , W , B , B , W , W , W , B , '2','2','1',' ',' ',' ',' ','\n' },
        {  B , B , B , B , B , B , W , W , W , W , W , W , W , W , B , '6',' ',' ',' ',' ',' ',' ','\n' },
        {  B , W , W , W , W , B , B , B , B , W , W , W , W , W , B , '1','4',' ',' ',' ',' ',' ','\n' },
        {  B , B , B , B , W , W , W , W , B , B , B , B , B , W , B , '4','5','1',' ',' ',' ',' ','\n' },
        {  B , B , B , B , B , B , B , W , W , W , W , W , B , B , B , '7','3',' ',' ',' ',' ',' ','\n' },
        {  B , W , W , B , B , B , B , B , B , B , B , W , W , W , B , '8','1',' ',' ',' ',' ',' ','\n' },
        {  B , B , W , W , W , W , W , B , B , B , B , B , B , B , B , '2','8',' ',' ',' ',' ',' ','\n' },
        {  W , W , B , B , B , B , W , W , W , W , W , W , B , B , B , '4','3',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , B , B , B , B , W , W , W , W , B , '4','1',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , W , W , W , W , B , B , B , B , W , '4',' ',' ',' ',' ',' ',' ','\n' },
        { '8','3','1','1','1','1','1','1','3','1','1','1','2','1','11','\n'			                    },
        { ' ','2','1','1','1','2','1','1','2','1','1','1','2','1',' ','\n'					            },
        { ' ','1','2','3','2','2','2','2','2','2','2','1','2','2',' ','\n'					            },
        { ' ',' ','1','1','1','1','1','1','1','1','1','1','1','1',' ','\n'					            },
    },
    /*  パンダ  */
    {
        { W , W , W , W , W , W , W , W , W , W , W , W , W , W , W , ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n' },
        { W , W , B , W , W , W , W , W , W , W , W , W , B , W , W , '1' ,'1',' ',' ',' ',' ',' ','\n' },
        { W , B , B , B , W , W , W , W , W , W , W , B , B , B , W , '3' ,'3',' ',' ',' ',' ',' ','\n' },
        { B , B , B , B , B , B , B , B , B , B , B , B , B , B , B , '15',' ',' ',' ',' ',' ',' ','\n' },
        { B , B , B , B , W , W , W , W , W , W , W , B , B , B , B , '4' ,'4',' ',' ',' ',' ',' ','\n' },
        { B , B , B , W , W , W , W , W , W , W , W , W , B , B , B , '3' ,'3',' ',' ',' ',' ',' ','\n' },
        { W , B , W , W , B , B , W , W , W , B , B , W , W , B , W , '1' ,'2','2','1',' ',' ',' ','\n' },
        { W , B , W , B , B , W , W , W , W , W , B , B , W , B , W , '1' ,'2','2','1',' ',' ',' ','\n' },
        { W , B , W , B , B , B , W , W , W , B , B , B , W , B , W , '1' ,'3','3','1',' ',' ',' ','\n' },
        { W , B , W , B , B , B , W , W , W , B , B , B , W , B , W , '1' ,'3','3','1',' ',' ',' ','\n' },
        { W , B , W , B , B , W , W , W , W , W , B , B , W , B , W , '1' ,'2','2','1',' ',' ',' ','\n' },
        { W , B , W , W , W , W , B , B , B , W , W , W , W , B , W , '1' ,'3','1',' ',' ',' ',' ','\n' },
        { W , W , B , W , W , W , W , B , W , W , W , W , B , W , W , '1' ,'1','1',' ',' ',' ',' ','\n' },
        { W , W , W , B , W , W , B , W , B , W , W , B , W , W , W , '1' ,'1','1','1',' ',' ',' ','\n' },
        { W , W , W , W , B , B , W , W , W , B , B , W , W , W , W , '2' ,'2',' ',' ',' ',' ',' ','\n' },
        { '3','10','5','3','1','1','1','1','1','1','1','3','5','10','3','\n'                            },
        { ' ',' ' ,'1','4','5','1','1','2','1','1','5','4','1',' ' ,' ','\n'                            },
        { ' ',' ' ,' ','1','1','2','1',' ','1','2','1','1',' ',' ' ,' ','\n'                            },
        { ' ',' ' ,' ',' ',' ','1',' ',' ',' ','1',' ',' ',' ',' ' ,' ','\n'                            },
    },
    /*  ピース  */
    {
        { W , W , W , W , B , B , W , W , W , W , W , B , W , W , W , '2','1',' ',' ',' ',' ',' ','\n' },
        { W , W , W , W , W , B , W , W , W , W , B , B , W , W , W , '1','2',' ',' ',' ',' ',' ','\n' },
        { W , W , W , W , W , B , B , W , W , W , B , B , W , W , W , '2','2',' ',' ',' ',' ',' ','\n' },
        { W , W , W , W , W , W , B , B , W , W , B , W , W , W , W , '2','1',' ',' ',' ',' ',' ','\n' },
        { W , W , W , W , W , W , B , B , W , B , B , W , W , W , W , '2','2',' ',' ',' ',' ',' ','\n' },
        { W , W , W , W , W , W , W , B , B , B , W , W , W , W , W , '3',' ',' ',' ',' ',' ',' ','\n' },
        { W , W , W , W , W , W , W , B , B , B , W , W , W , W , W , '3',' ',' ',' ',' ',' ',' ','\n' },
        { W , W , W , W , W , B , B , W , W , W , B , B , W , W , W , '2','2',' ',' ',' ',' ',' ','\n' },
        { W , W , W , W , B , B , W , W , W , W , W , W , B , W , W , '2','1',' ',' ',' ',' ',' ','\n' },
        { W , W , W , W , B , W , W , W , W , W , W , W , B , B , W , '1','2',' ',' ',' ',' ',' ','\n' },
        { W , W , W , W , B , W , W , B , B , W , W , W , W , B , W , '1','2','1',' ',' ',' ',' ','\n' },
        { W , W , W , W , B , W , B , B , B , W , W , W , B , B , W , '1','3','2',' ',' ',' ',' ','\n' },
        { W , W , W , W , W , B , B , B , B , W , W , B , B , W , W , '4','2',' ',' ',' ',' ',' ','\n' },
        { W , W , W , W , W , W , B , B , B , B , B , B , W , W , W , '6',' ',' ',' ',' ',' ',' ','\n' },
        { W , W , W , W , W , W , W , W , W , W , W , W , W , W , W , ' ',' ',' ',' ',' ',' ',' ','\n' },
        { ' ',' ',' ',' ','1','3','3','4','2','3','4','3','2','3',' ','\n'                             },
        { ' ',' ',' ',' ','4','2','1','4','4','1','1','1','2',' ',' ','\n'                             },
        { ' ',' ',' ',' ',' ','1','3',' ',' ',' ','1','2',' ',' ',' ','\n'                             },
        { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\n'                             },
    },
    /*  ペンギン  */
    {
        { W , W , W , W , B , B , B , W , W , W , W , W , W , W , W , '3' ,' ',' ',' ',' ',' ',' ','\n' },
        { W , W , W , B , W , B , B , B , B , W , W , W , W , W , W , '1' ,'4',' ',' ',' ',' ',' ','\n' },
        { W , W , B , B , B , B , B , B , B , B , W , W , W , W , W , '8' ,' ',' ',' ',' ',' ',' ','\n' },
        { W , B , B , B , B , B , B , B , B , B , B , W , W , W , W , '10',' ',' ',' ',' ',' ',' ','\n' },
        { W , W , W , W , B , B , B , B , B , B , B , B , W , W , W , '8' ,' ',' ',' ',' ',' ',' ','\n' },
        { W , W , W , B , W , W , W , B , B , B , B , B , W , W , W , '1' ,'5',' ',' ',' ',' ',' ','\n' },
        { W , W , W , B , W , W , W , B , B , B , B , B , W , W , W , '1' ,'5',' ',' ',' ',' ',' ','\n' },
        { W , W , B , W , W , W , B , B , B , B , B , B , B , W , W , '1' ,'7',' ',' ',' ',' ',' ','\n' },
        { W , W , B , W , W , B , B , B , B , B , B , B , B , W , W , '1' ,'8',' ',' ',' ',' ',' ','\n' },
        { W , W , B , W , W , B , B , B , B , B , B , B , B , W , W , '1' ,'8',' ',' ',' ',' ',' ','\n' },
        { W , W , B , W , B , B , B , B , B , B , B , B , B , W , W , '1' ,'9',' ',' ',' ',' ',' ','\n' },
        { W , W , B , W , B , B , W , B , B , B , B , B , B , B , W , '1' ,'2','7',' ',' ',' ',' ','\n' },
        { W , W , B , W , W , W , W , B , B , B , B , B , B , B , W , '1' ,'7',' ',' ',' ',' ',' ','\n' },
        { W , B , B , W , B , B , W , B , B , B , B , B , B , B , W , '2' ,'2','7',' ',' ',' ',' ','\n' },
        { B , B , B , B , B , B , B , B , B , B , B , B , B , B , W , '14',' ',' ',' ',' ',' ',' ','\n' },
        { '1','1','2','3','1','5','5','14','14','13','12','11','9','4',' ','\n'                         },
        { ' ','2','8','2','3','4','4',' ' ,' ' ,' ' ,' ' ,' ' ,' ',' ',' ','\n'                         },
        { ' ',' ',' ','1','2','2','1',' ' ,' ' ,' ' ,' ' ,' ' ,' ',' ',' ','\n'                         },
        { ' ',' ',' ',' ','2',' ',' ',' ' ,' ' ,' ' ,' ' ,' ' ,' ',' ',' ','\n'                         },
    },
    /*  リンゴ  */
    {
        { W , W , W , W , W , W , W , B , W , B , W , W , W , W , W , '1','1',' ',' ',' ',' ',' ','\n' },
        { W , W , W , W , W , W , W , B , B , W , W , W , W , W , W , '2',' ',' ',' ',' ',' ',' ','\n' },
        { W , W , W , W , W , W , W , B , W , W , W , W , W , W , W , '1',' ',' ',' ',' ',' ',' ','\n' },
        { W , W , W , B , B , B , B , B , B , B , B , B , W , W , W , '9',' ',' ',' ',' ',' ',' ','\n' },
        { W , W , B , W , W , W , W , B , W , W , W , W , B , W , W , '1','1','1',' ',' ',' ',' ','\n' },
        { W , B , W , W , W , B , W , B , W , B , W , W , W , B , W , '1','1','1','1','1',' ',' ','\n' },
        { B , W , W , W , W , W , B , B , B , W , W , W , W , W , B , '1','3','1',' ',' ',' ',' ','\n' },
        { B , W , W , W , W , W , W , W , W , W , W , W , W , W , B , '1','1',' ',' ',' ',' ',' ','\n' },
        { B , W , W , W , W , W , W , W , W , W , W , W , W , W , B , '1','1',' ',' ',' ',' ',' ','\n' },
        { B , W , W , W , W , W , W , W , W , W , W , W , W , W , B , '1','1',' ',' ',' ',' ',' ','\n' },
        { B , W , W , W , W , W , W , W , W , W , W , W , W , W , B , '1','1',' ',' ',' ',' ',' ','\n' },
        { B , W , W , W , W , W , W , W , W , W , W , W , W , W , B , '1','1',' ',' ',' ',' ',' ','\n' },
        { W , B , W , W , W , W , W , W , W , W , W , W , W , B , W , '1','1',' ',' ',' ',' ',' ','\n' },
        { W , W , B , W , W , W , W , W , W , W , W , W , B , W , W , '1','1',' ',' ',' ',' ',' ','\n' },
        { W , W , W , B , B , B , B , B , B , B , B , B , W , W , W , '9',' ',' ',' ',' ',' ',' ','\n' },
        { '6','1','1','1','1','1','1','7','1','1','1','1','1','1','6','\n'                             },
        { ' ','1','1','1','1','1','1','1','1','1','1','1','1','1',' ','\n'                             },
        { ' ',' ',' ',' ',' ','1','1',' ','1','1',' ',' ',' ',' ',' ','\n'                             },
        { ' ',' ',' ',' ',' ',' ',' ',' ','1','1',' ',' ',' ',' ',' ','\n'                             },
    },
    /*  傘  */
    {
        {  W , W , W , W , W , W , W , W , W , W , W , W , W , W , W , ' ',' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , W , B , W , W , W , W , W , W , W , '1',' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , B , B , B , W , W , W , W , W , W , '3',' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , B , B , W , W , W , B , B , W , W , W , W , '2','2',' ',' ',' ',' ',' ','\n' },
        {  W , W , B , B , B , W , W , W , W , W , B , B , B , W , W , '3','3',' ',' ',' ',' ',' ','\n' },
        {  W , B , B , W , W , W , W , W , W , W , W , W , B , B , W , '2','2',' ',' ',' ',' ',' ','\n' },
        {  W , B , W , W , W , W , W , W , W , W , W , W , W , B , W , '1','1',' ',' ',' ',' ',' ','\n' },
        {  B , W , B , W , B , W , B , B , B , W , B , W , B , W , B , '1','1','1','3','1','1','1','\n' },
        {  W , B , W , B , W , B , W , B , W , B , W , B , W , B , W , '1','1','1','1','1','1','1','\n' },
        {  W , W , W , W , W , W , W , B , W , W , W , W , W , W , W , '1',' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , W , B , W , W , W , W , W , W , W , '1',' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , W , B , W , W , W , W , W , W , W , '1',' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , W , B , W , W , B , W , W , W , W , '1','1',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , W , B , W , W , B , W , W , W , W , '1','1',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , W , W , W , W , B , B , W , W , W , W , W , '2',' ',' ',' ',' ',' ',' ','\n' },
        { '1','2','2','1','2','1','1','2','1','1','2','1','2','2','1','\n'			                    },
        { ' ','1','1','1','1','1','1','7','1','1','1','1','1','1',' ','\n'					            },
        { ' ',' ',' ',' ',' ',' ',' ',' ','1','1','2',' ',' ',' ',' ','\n'					            },
        { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\n'					            },
    },
    /*  時計  */
    {
        {  W , W , W , W , B , B , B , B , B , B , B , W , W , W , W , '7',' ',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , B , B , W , W , W , W , W , B , B , W , W , W , '2','2',' ',' ',' ',' ',' ','\n' },
        {  W , W , B , B , W , W , W , B , W , W , W , B , B , W , W , '2','1','2',' ',' ',' ',' ','\n' },
        {  W , B , B , W , W , W , W , B , W , W , W , W , B , B , W , '2','1','2',' ',' ',' ',' ','\n' },
        {  B , B , W , W , W , W , W , B , W , W , W , W , W , B , B , '2','1','2',' ',' ',' ',' ','\n' },
        {  B , W , W , W , W , W , W , B , W , W , W , W , W , W , B , '1','1','1',' ',' ',' ',' ','\n' },
        {  B , W , W , W , W , W , W , B , W , W , W , W , W , W , B , '1','1','1',' ',' ',' ',' ','\n' },
        {  B , W , W , W , W , W , W , B , B , B , B , B , W , W , B , '1','5','1',' ',' ',' ',' ','\n' },
        {  B , W , W , W , W , W , W , W , W , W , W , W , W , W , B , '1','1',' ',' ',' ',' ',' ','\n' },
        {  B , W , W , W , W , W , W , W , W , W , W , W , W , W , B , '1','1',' ',' ',' ',' ',' ','\n' },
        {  B , B , W , W , W , W , W , W , W , W , W , W , W , B , B , '2','2',' ',' ',' ',' ',' ','\n' },
        {  W , B , B , W , W , W , W , W , W , W , W , W , B , B , W , '2','2',' ',' ',' ',' ',' ','\n' },
        {  W , W , B , B , W , W , W , W , W , W , W , B , B , W , W , '2','2',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , B , B , W , W , W , W , W , B , B , W , W , W , '2','2',' ',' ',' ',' ',' ','\n' },
        {  W , W , W , W , B , B , B , B , B , B , B , W , W , W , W , '7',' ',' ',' ',' ',' ',' ','\n' },
        { '7','2','2','2','2','1','1','1','1','1','2','2','2','2','7','\n'			                    },
        { ' ','2','2','2','2','1','1','6','1','1','1','1','2','2',' ','\n'					            },
        { ' ',' ',' ',' ',' ',' ',' ','1','1','1','2','2',' ',' ',' ','\n'					            },
        { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\n'					            },
    },
    /*  非常口の人  */
    {
        {  B , B , B , B , B , B , B , B , B , B , B , B , B , B , B , '15',' ',' ',' ',' ',' ',' ','\n' },
        {  B , B , B , W , W , W , W , W , W , W , W , W , B , B , B , '3' ,'3',' ',' ',' ',' ',' ','\n' },
        {  B , B , B , W , W , B , B , W , W , W , W , W , B , B , B , '3' ,'2','3',' ',' ',' ',' ','\n' },
        {  B , B , B , W , W , B , B , W , W , W , W , W , B , B , B , '3' ,'2','3',' ',' ',' ',' ','\n' },
        {  B , B , B , W , W , W , W , W , W , W , W , W , B , B , B , '3' ,'3',' ',' ',' ',' ',' ','\n' },
        {  B , B , B , W , W , W , B , B , B , B , W , W , B , B , B , '3' ,'4','3',' ',' ',' ',' ','\n' },
        {  B , B , B , W , W , B , B , B , W , W , B , W , B , B , B , '3' ,'3','1','3',' ',' ',' ','\n' },
        {  B , B , B , B , B , W , B , B , B , W , W , B , B , B , B , '5' ,'3','4',' ',' ',' ',' ','\n' },
        {  B , B , B , W , W , W , B , B , B , W , B , W , B , B , B , '3' ,'3','1','3',' ',' ',' ','\n' },
        {  B , B , B , W , W , W , B , B , B , W , W , W , B , B , B , '3' ,'3','3',' ',' ',' ',' ','\n' },
        {  B , B , B , W , W , W , B , W , B , W , W , W , B , B , B , '3' ,'1','1','3',' ',' ',' ','\n' },
        {  B , B , B , W , W , B , B , W , B , W , W , W , B , B , B , '3' ,'2','1','3',' ',' ',' ','\n' },
        {  B , B , B , W , B , B , W , W , B , B , B , B , B , B , B , '3' ,'2','7',' ',' ',' ',' ','\n' },
        {  B , B , B , B , B , W , W , W , W , W , W , W , W , B , B , '5' ,'2',' ',' ',' ',' ',' ','\n' },
        {  B , B , B , B , B , W , W , W , W , W , W , W , W , W , B , '5' ,'1',' ',' ',' ',' ',' ','\n' },
        { '15','15','15','1','1','1','1','1','1','1','1','1','13','14','15','\n'			             },
        { ' ' ,' ' ,' ' ,'1','1','2','2','5','1','1','1','1',' ' ,' ' ,' ' ,'\n'			             },
        { ' ' ,' ' ,' ' ,'2','3','1','7',' ','6','1','1','1',' ' ,' ' ,' ' ,'\n'			             },
        { ' ' ,' ' ,' ' ,' ',' ','2',' ',' ',' ',' ','1',' ',' ' ,' ' ,' ' ,'\n'         		         },
    }
};
void setPositions() {
    Question_Button[0] = new WindowArea(1.1 / 8, 5.6 / 11, 0.90 / 8, 8.2 / 12 - (5.6 / 11));
    Question_Button[1] = new WindowArea(2.1 / 8, 5.0 / 11, 3.05 / 8 - (2.1 / 8), 7.6 / 12 - (5.0 / 11));
    Question_Button[2] = new WindowArea(3.1 / 8, 5.6 / 11, 4.05 / 8 - (3.1 / 8), 8.2 / 12 - (5.6 / 11));
    Question_Button[3] = new WindowArea(4.1 / 8, 5.0 / 11, 5.05 / 8 - (4.1 / 8), 7.6 / 12 - (5.0 / 11));
    Question_Button[4] = new WindowArea(5.1 / 8, 5.6 / 11, 6.05 / 8 - (5.1 / 8), 8.2 / 12 - (5.6 / 11));
    Question_Button[5] = new WindowArea(6.1 / 8, 5.0 / 11, 7.05 / 8 - (6.1 / 8), 7.6 / 12 - (5.0 / 11));
    Question_Button[6] = new WindowArea(1.1 / 8, 8.5 / 11, 2.00 / 8 - (1.1 / 8), 10.6 / 11 - (8.5 / 11));
    Question_Button[7] = new WindowArea(2.1 / 8, 7.9 / 11, 3.05 / 8 - (2.1 / 8), 10.0 / 11 - (7.9 / 11));
    Question_Button[8] = new WindowArea(3.1 / 8, 8.5 / 11, 4.05 / 8 - (3.1 / 8), 10.6 / 11 - (8.5 / 11));
    Question_Button[9] = new WindowArea(4.1 / 8, 7.9 / 11, 5.05 / 8 - (4.1 / 8), 10.0 / 11 - (7.9 / 11));
    Question_Button[10] = new WindowArea(5.1 / 8, 8.5 / 11, 6.05 / 8 - (5.1 / 8), 10.6 / 11 - (8.5 / 11));
    Question_Button[11] = new WindowArea(6.1 / 8, 7.9 / 11, 7.05 / 8 - (6.1 / 8), 10.0 / 11 - (7.9 / 11));
}