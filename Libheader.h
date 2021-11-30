
#ifndef LIBHEADER_H
#define LIBHEADER_H
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/###**Utile.Structure**###\/\/\/\/\/\/\/\/\/\/\/\/\/\*/

typedef struct gameData
{
   int numberOfCaseAvailable;
   int ** ArrCopy;
   char *str;
   char * str2; 
   int gameScore;
   int size2DArr;
   char choice;
   char quitKey;
   int gameOver;
}T_gameD;

/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/###*UTILIFUNC.C*###\/\/\/\/\/\/\/\/\/\/\/\/\/\*/

int Random2or4();
void    PrintGrid(int **T, int dim, T_gameD * game);
void Print1DArr(int * T, int dim);
int ** Create2Darr(int dim);
void    shiftLineOfMat(int **T, int n, int Line, int * shiftedArr);
void    free2Darr(int ** Mat, int dim);
int     StoreOnlyNums(int * Arr, int dim);
void    putArrtoZero(int * T, int n);
void Copy2DArrAddElem(int ** Arr, int dim, T_gameD * game);


/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/###**ShiftLeftFunc.c**###\/\/\/\/\/\/\/\/\/\/\/\/\/\*/

void    checkAddShiftLeft(int * Arr, int dim, T_gameD * game);
void    shiftLeft(int **T, int n, T_gameD * game);

/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/###**ShiftRightFunc.c**###\/\/\/\/\/\/\/\/\/\/\/\/\/\*/

void  ShiftRight1dArr(int * Arr,  int n, int numberOfnums);
int    checkAddShiftRight2(int * Arr, int dim, int numberOfelembefore,T_gameD * game);
void    shiftRight(int **T, int n, T_gameD * game);

/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/###**ShiftUp&Down.c**###\/\/\/\/\/\/\/\/\/\/\/\/\/\*/

void    TransposeMat(int **Mat, int dim);
void TransposeBackMat(int **Mat, int dim);
void    shiftDown(int **Mat, int dim, T_gameD * game);
void    shiftUp(int **Mat, int dim, T_gameD * game);

/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/###**GenRandom.c**###\/\/\/\/\/\/\/\/\/\/\/\/\/\*/

int Random2or4();
int    AddRand2or4AtRandMat(int ** Arr, int dim, T_gameD * game);
void    AddRand2AtRandMat(int ** Arr, int dim, T_gameD * game);

/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/###**CheckFun.c**###\/\/\/\/\/\/\/\/\/\/\/\/\/\*/

int checkIfaCopy(int ** Arr, int dim, T_gameD * game);
int checkIfGameOver(int ** Arr, int dim);


/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/###**GameStartfun.c**###\/\/\/\/\/\/\/\/\/\/\/\/\/\*/


void    InitilizeAll(T_gameD * game); 
void    PlayGame(T_gameD * game, int ** Arr); 
int    PrintAnimation();



#endif