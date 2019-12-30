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

int **flipAndInvertImage(int **A, int ARowSize, const int *AColSizes, int **columnSizes, int *returnSize)
{
    int i, j;

    int **ret = (int **)malloc(ARowSize * sizeof(int *));  //在函数中使用指针创建二维数组，需要一个二级指针和一个指针数组

    *returnSize  = ARowSize;
    *columnSizes = (int *)malloc(sizeof(int) * ARowSize);

    for(i = 0; i < ARowSize; i++)
    {
        (*columnSizes)[i] = AColSizes[i];

        ret[i] = (int *)malloc(AColSizes[i] * sizeof(int));

        for(j = 0; j < (AColSizes[i] + 1) / 2; j++)
        {
            ret[i][j]                    = A[i][AColSizes[i] - 1 - j] ^ 1;
            ret[i][AColSizes[i] - 1 - j] = A[i][j] ^ 1;
        }
    }
    return ret;
}

int main(void)
{
#if 1
    int  row1[]    = {1, 2, 3};
    int  row2[]    = {4, 5, 6};
    int *A[3]      = {row1, row2};
    int  AColSizes = 3;

    int **ret;
    int   row;
    int * col;
    ret = transpose(A, 2, &AColSizes, &row, &col);

#else

    int  row1[]    = {5};
    int  row2[]    = {8};
    int *A[2]      = {row1, row2};
    int  AColSizes = 1;

    int **ret;
    int   row;
    int * col;
    ret = transpose(A, 2, &AColSizes, &row, &col);
#endif

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < *col; j++)
        {
            printf("%d\t", ret[i][j]);
        }
        printf("\n");
    }

    return 0;
}
