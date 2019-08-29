/*
给定一个矩阵 A， 返回 A 的转置矩阵。

矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。

 

示例 1：

输入：[[1,2,3],[4,5,6],[7,8,9]]
输出：[[1,4,7],[2,5,8],[3,6,9]]
示例 2：

输入：[[1,2,3],[4,5,6]]
输出：[[1,4],[2,5],[3,6]]
 

提示：

1 <= A.length <= 1000
1 <= A[0].length <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/transpose-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int** transpose(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes)
{
    int** r = malloc((*AColSize) * (sizeof(int*)));

    for(int i = 0; i < *AColSize; i++)
    {
        r[i] = malloc(ASize * sizeof(int));
        for(int j = 0; j < ASize; j++)
        {
            int* row_data = A[j];

            r[i][j] = row_data[i];
        }
    }
    *returnSize        = *AColSize;
    *returnColumnSizes = malloc(sizeof(int) * (*AColSize));
    for(int i = 0; i < *AColSize; i++)
    {
        returnColumnSizes[0][i] = ASize;
    }

    return r;
}

int main(void)
{
#if 0
    int  row1[]    = {1, 2, 3};
    int  row2[]    = {4, 5, 6};
    int* A[3]      = {row1, row2};
    int  AColSizes = 3;

    int** r;
    int   row;
    int*  col;
    r = transpose(A, 2, &AColSizes, &row, &col);

#else

    int  row1[]    = {5};
    int  row2[]    = {8};
    int* A[2]      = {row1, row2};
    int  AColSizes = 1;

    int** r;
    int   row;
    int*  col;
    r = transpose(A, 2, &AColSizes, &row, &col);
#endif

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < *col; j++)
        {
            printf("%d\t", r[i][j]);
        }
        printf("\n");
    }

    return 0;
}
