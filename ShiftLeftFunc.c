#include "Libheader.h"


void    checkAddShiftLeft(int * Arr, int dim, T_gameD * game)
{
    int aAdd = 0;
    int bAdd = 0;
    for (int i = 0; i < dim - 1; i++)
    {
        aAdd = Arr[i];
        bAdd = Arr[i + 1];
        if (aAdd == bAdd)
        {
            Arr[i] = aAdd + bAdd;
            game->gameScore += Arr[i];
            Arr[i + 1] = 0;
        }
    }
    //Print1DArr(Arr, dim);
    StoreOnlyNums(Arr, dim); // we do not nee the return value because shifting left doesnt need the number of elements
}

void    shiftLeft(int **T, int n, T_gameD * game)
{
    int * SenT1 = (int *) calloc(4, sizeof(int));
    int sizeOfnums = 0;
    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < n; j++)
       {
           if (T[i][j] != 0) 
           {
               SenT1[sizeOfnums] = T[i][j]; 
               sizeOfnums++;
           }
       }
       if (sizeOfnums > 0)
       {
           checkAddShiftLeft(SenT1, n, game); // we dont nee even to reshift the line after checkAddShiftLeft because its in the desired order
           shiftLineOfMat(T, n, i, SenT1);
           putArrtoZero(SenT1, n);
       }
       sizeOfnums = 0;
    }
    free(SenT1); 
}