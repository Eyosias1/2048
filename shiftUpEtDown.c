#include "Libheader.h"

void    TransposeMat(int **Mat, int dim)
{
    int ** tmp = Create2Darr(dim);
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            tmp[j][i] = Mat[i][j];
        }
    }
    for (int i = 0; i < dim; i++)
    {
       for (int j = 0; j < dim; j++)
       {
          Mat[i][j] = tmp[i][j];
       }
    }
    free2Darr(tmp, dim);
}

void TransposeBackMat(int **Mat, int dim)
{
    int ** tmp = Create2Darr(dim);
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            tmp[j][i] = Mat[i][j];
        }
    }
    for (int i = 0; i < dim; i++)
    {
       for (int j = 0; j < dim; j++)
       {
          Mat[i][j] = tmp[i][j];
       }
    }
    free2Darr(tmp, dim);
}

void    shiftDown(int **Mat, int dim, T_gameD * game)
{
    TransposeMat(Mat, dim);
    shiftRight(Mat, dim, game);
    TransposeBackMat(Mat, dim);
}

void    shiftUp(int **Mat, int dim, T_gameD * game)
{
    TransposeMat(Mat, dim);
    shiftLeft(Mat, dim, game);
    TransposeBackMat(Mat, dim);
}