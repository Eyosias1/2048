#include "Libheader.h"



void    PrintGrid(int **T, int dim, T_gameD * game)
{
    system("cls");
    for (int i = 0; i < dim; i++)
    {
        printf("\t\t\t\t\t");
        for (int j = 0; j < dim; j++)
        {
            if (T[i][j] == 0) {
                printf("  -  ");
            }
            else {
                printf("  %d  ", T[i][j]);
            }
            
        }
        printf("\n");
        if (i == 0) {
            printf("\t\t%s", game->str);
        }
        if (i == 1) {
            printf("\t\t     %d", game->gameScore);
        }
        if (i == 2) {
            printf("\t\t%s", game->str2);
        }
        printf("\n");
    }
}

void Print1DArr(int * T, int dim)
{
    for (int i = 0; i < dim; i++)
    {
       printf(" %d ", T[i]); 
    }
    printf("\n");
}


int ** Create2Darr(int dim)
{
    int ** Mat = (int **) calloc(dim, sizeof(int *));
    for (int i = 0; i < dim; i++)
    {
        Mat[i] = (int *) calloc(dim, sizeof(int));
    }
    return Mat; 
}

void Copy2DArrAddElem(int ** Arr, int dim, T_gameD * game)
{
    int numElem = 0;
    for (int i = 0; i < dim; i++)
    {
       for (int j = 0; j < dim; j++)
       {
           game->ArrCopy[i][j] = Arr[i][j];
           if (Arr[i][j] != 0)
           {
               numElem++;
           } 
       } 
    }
    game->numberOfCaseAvailable = numElem;
}

void    shiftLineOfMat(int **T, int n, int Line, int * shiftedArr)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == Line)
            {
                T[i][j] = shiftedArr[j];
            }
        }   
    }  
}

void    free2Darr(int ** Mat, int dim)
{
    for (int i = 0; i < dim; i++)
    {
       free(Mat[i]); 
    }
    free(Mat);    
}

int     StoreOnlyNums(int * Arr, int dim)
{
    int * stored = (int *) calloc(dim, sizeof(int));
    int numberOfelem = 0;
    for (int i = 0; i < dim; i++)
    {
       if (Arr[i] != 0)
       {
           stored[numberOfelem] = Arr[i];
           numberOfelem++;
       } 
    }
    for (int i = 0; i < dim; i++)
    {
        Arr[i] = stored[i]; 
    }
    free(stored);
    return numberOfelem;
}

void    putArrtoZero(int * T, int n)
{
    for (int i = 0; i < n; i++)
    {
        T[i] = 0;
    }
}