#include "Libheader.h"

int checkIfaCopy(int ** Arr, int dim, T_gameD * game)
{
    for (int i = 0; i < dim; i++)
    {
       for (int j = 0; j < dim; j++)
       {
          if( Arr[i][j] != game->ArrCopy[i][j])
          {
              return 1;
          } 
       } 
    }
    return 0;
}


int checkIfGameOver(int ** Arr, int dim)
{
    int tmp = 0;
    for (int i = 0; i < dim; i++)
    {
       for (int j = 0; j < dim - 1; j++)
       {
          tmp = Arr[i][j + 1];
          if ( (Arr[i][j] == tmp) || (tmp == 0 || Arr[i][j] == 0))
          {
              return 1;
          }
       } 
    }
    TransposeMat(Arr, dim);
    for (int i = 0; i < dim; i++)
    {
       for (int j = 0; j < dim - 1; j++)
       {
          tmp = Arr[i][j + 1];
          if ( (Arr[i][j] == tmp)  || (tmp == 0 || Arr[i][j] == 0) )
          {
              return 1;
          }
       } 
    }
    return 0; 
}