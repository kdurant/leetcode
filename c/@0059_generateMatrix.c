/*
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
{
    *returnSize  = n;
    int odd_even = 0;  // 0偶数，1奇数

    int** res = (int**)malloc(n * sizeof(int*));

    for(int i = 0; i < n; i++)
    {
        res[i] = malloc(n * sizeof(int));

        if(odd_even == 0)
        {
            for(int j = 0; j < n; j++)
            {
                res[i][j] = (2 * i) * n + j + 1;
            }
        }
        else
        {
            for(int j = n - 1; j >= 0; j--)
            {
                res[i][j] = (2 * i - 1) * n + j + 1;
            }
        }
    }
    *returnColumnSizes = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        returnColumnSizes[0][i] = n;
    }
    return res;
}

