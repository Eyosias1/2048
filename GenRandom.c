#include "Libheader.h"

int Random2or4()
{
    int num = rand() % 2;
    return (num > 0) ? 4 : 2;
}

int    AddRand2or4AtRandMat(int ** Arr, int dim, T_gameD * game)
{
    srand(time(NULL));
    int i2 = 0;
    int j2 = 0;
    int breakG = 0;
    while (breakG != dim * dim)
    {
        i2 = rand()%dim;
        j2 = rand()%dim;
        if (Arr[i2][j2] == 0)
        {
            Arr[i2][j2] = Random2or4();
            return 1;
        }
        breakG++;
    }
    return 0;
}


void    AddRand2AtRandMat(int ** Arr, int dim, T_gameD * game)
{
    srand(time(NULL));
    int i = 0;
    int j = 0;
    int i2 = 0;
    int j2 = 0;
    while (game->numberOfCaseAvailable == 0)
    {
        i2 = rand()%dim;
        j2 = rand()%dim;
        Arr[i2][j2] = 2;
        game->numberOfCaseAvailable += 1;
    }
    while (game->numberOfCaseAvailable == 1)
    {
        i = rand()%dim;
        j = rand()%dim;
        if (Arr[i][j] == 0)
        {
            Arr[i][j] = 2;
            game->numberOfCaseAvailable += 1;
        }
    }
}