#include "Libheader.h"

void  ShiftRight1dArr(int * Arr,  int n, int numberOfnums)
{
    int * Tshift = (int *) calloc(4, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if (i < numberOfnums)
        {
            Tshift[n - 1 - i] = Arr[numberOfnums - 1 - i];
        }
    }
    for (int i = 0; i < n; i++)
    {
       Arr[i] = Tshift[i];
    }
    free(Tshift); 
}

int    checkAddShiftRight2(int * Arr, int dim, int numberOfelembefore, T_gameD * game)
{
    int aAdd = 0;
    int bAdd = 0;
    int numberOfelem = 0;
    for (int i = dim - 1; i >= 1; i--)
    {
        aAdd = Arr[i];
        bAdd = Arr[i - 1];
        if (aAdd == bAdd)
        {
            Arr[i] = aAdd + bAdd;
            game->gameScore += Arr[i];
            Arr[i - 1] = 0;
        }
    }
    numberOfelem = StoreOnlyNums(Arr, dim);
    return numberOfelem;
}


void    shiftRight(int **T, int n, T_gameD * game)
{
    int * SenT1 = (int *) calloc(4, sizeof(int));
    int sizeOfnums = 0;
    int result = 0;
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
           ShiftRight1dArr(SenT1, n, sizeOfnums);
           result = checkAddShiftRight2(SenT1, n, sizeOfnums, game);
           ShiftRight1dArr(SenT1, n , result);
           shiftLineOfMat(T, n, i, SenT1);
           putArrtoZero(SenT1, n);
       }
       sizeOfnums = 0;
       result = 0;
    }
    free(SenT1);   
}