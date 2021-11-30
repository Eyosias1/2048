#include "Libheader.h"


void    InitilizeAll(T_gameD * game) {
    game->size2DArr = 4;
    game->choice = '\0';
    game->quitKey = '\0';
    game->gameOver = 1;
    game->numberOfCaseAvailable = 0;
    game->str = "====Score====";
    game->str2 = "=============";
    game->gameScore = 0;
    game->ArrCopy = Create2Darr(game->size2DArr);
}

int    PrintAnimation()
{
    char gamestart = '\0';
    printf("\t\t\t\t\t++++++++++++++++++++++++++++++\n\t\t\t\t\t++++++++++++++++++++++++++++++\n\t\t\t\t\t+           2048             +\n\t\t\t\t\t++++++++++++++++++++++++++++++\n\t\t\t\t\t++++++++++++++++++++++++++++++\n\n\n\t\t\t\t");
    printf("=========== Enter 'S' To start game===========\n");
    printf("\t\t\t\t\t===== chose : ");
    scanf(" %c", &gamestart);
    if (gamestart == 'S')
    {
       return 1; 
    }
    return 0; 
}








void    PlayGame(T_gameD * game, int ** Arr) {
    while (game->gameOver != 0)
    {
        Copy2DArrAddElem(Arr, game->size2DArr, game);
        printf("===chose the keys i to up, to go down k, to go right l, and to go left j\n");
        printf("\t\t================ chose : ");
        scanf(" %c", &game->choice);
        switch (game->choice)
        {
            case 'j':
                shiftLeft(Arr, game->size2DArr,game);
            break;

            case 'k':
                shiftDown(Arr, game->size2DArr,game);
            break;

            case 'l':
                shiftRight(Arr, game->size2DArr,game);
                printf("good\n");
            break;

            case 'i':
                shiftUp(Arr, game->size2DArr,game);
            break;

            default:
                game->gameOver = 0;
                game->quitKey = game->choice;
            break;
        }
        if (checkIfaCopy(Arr, game->size2DArr, game) == 1)
        {
            AddRand2or4AtRandMat(Arr, game->size2DArr, game);
        }
        if (game->numberOfCaseAvailable == (game->size2DArr * game->size2DArr))
        {
            game->gameOver = checkIfGameOver(Arr, game->size2DArr);
        }
        PrintGrid(Arr, game->size2DArr, game);
        game->choice = '\0';
    }
    if (game->gameOver == 0 && game->quitKey != '\0') {
        printf("\t\t\t\tGame Over you chose =='%c'== to leave\n", game->quitKey);
    }
    else {
        printf("\t\t\t=======Game Over========\n");
    }
}