/*
给你一个整数 n，请你返回 任意 一个由 n 个 各不相同 的整数组成的数组，并且这 n 个数相加和为 0 。

示例 1：

输入：n = 5
输出：[-7,-1,1,3,4]
解释：这些数组也是正确的 [-5,-1,1,2,3]，[-3,-1,2,-2,4]。
示例 2：

输入：n = 3
输出：[-1,0,1]
示例 3：

输入：n = 1
输出：[0]
 

提示：

1 <= n <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-n-unique-integers-sum-up-to-zero
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// a[5]  middle = 2
// a[6]  middle = 3
int* sumZero(int n, int* returnSize)
{
    int* ret    = calloc(n, sizeof(int));
    int  middle = n / 2;
    *returnSize = n;

    for(int i = 0; i < middle; i++)
        ret[i] = -(middle - i);

    if(n % 2 == 0)
    {
        for(int i = middle; i < n; i++)
            ret[i] = -ret[i - middle];
    }
    else
    {
        ret[middle] = 0;
        for(int i = middle + 1; i < n; i++)
            ret[i] = -ret[i - middle - 1];
    }
    return ret;
}

int main(void)
{
    int  returnSize;
    int* ret = sumZero(1, &returnSize);

    for(int i = 0; i < returnSize; i++)
    {
        printf("%d\n", ret[i]);
    }

    return 0;
}

