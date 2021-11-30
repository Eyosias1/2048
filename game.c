#include "Libheader.h"



int main()
{
    T_gameD  * game = malloc(sizeof(T_gameD));
    InitilizeAll(game);
    int ** Arr = Create2Darr(game->size2DArr);
    AddRand2AtRandMat(Arr, game->size2DArr, game);
    system("cls");
    if (PrintAnimation() == 1)
    {
        PrintGrid(Arr, game->size2DArr, game);
        PlayGame(game, Arr);   
    }
    else {
        system("cls");
    } 
    free2Darr(Arr, game->size2DArr);
    free2Darr(game->ArrCopy, game->size2DArr);
    free(game);
    return 0;
}