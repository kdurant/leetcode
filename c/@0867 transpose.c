#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * @brief 
 * 
 * @param A     数组地址
 * @param ASize         几行
 * @param AColSize      几列
 * @param returnSize    
 * @param returnColumnSizes 
 * @return int** 
 */
int** transpose(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes)
{
    if( A == NULL )
        return NULL;
    
    int **res = (int**)malloc(sizeof(int*)*(*AColSize));
    returnColumnSizes[0] = (int*)malloc(sizeof(int)*(*AColSize));
    *returnSize = *AColSize;
    
    //分配内存
    for( int i = 0; i < *AColSize; i++ )
    {
        res[i] = (int*)malloc(sizeof(int)*ASize);
        returnColumnSizes[0][i] = ASize;
    }
    //矩阵转置
    for( int i = 0; i < ASize; i++ )
    {
        for( int j = 0; j < *AColSize; j++ )
        {
            res[j][i] = A[i][j];
        }
    }
    return res;
}

int main()
{
    int row = 3;
    int col = 3;
    int ** res ;
    int returnSize;
    int twoArray[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    transpose((int **)twoArray, 3, &col, &returnSize, )
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            printf("%p\t", &twoArray[i][j]);
        }
        printf("\n");        
    }
    
    return 0;
}