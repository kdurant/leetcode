/*
给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。

示例 1:

输入: [1,4,3,2]

输出: 4
解释: n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).
提示:

n 是正整数,范围在 [1, 10000].
数组中的元素范围在 [-10000, 10000].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/array-partition-i
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int compare(const void *a , const void *b)
{
    return *(int *)a - *(int *)b;
}

int arrayPairSum(int* nums, int numsSize){
    int res = 0;
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize; i += 2)
    {
        res += *(nums+i);
    }
    return res;
}

int main()
{
    int A[] = {1,4,3,2};
    printf("%d\n", arrayPairSum(A, sizeof(A)/4));
    return 0;
}