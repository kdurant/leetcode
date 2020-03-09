/*
给定一个未经排序的整数数组，找到最长且连续的的递增序列。

示例 1:

输入: [1,3,5,4,7]
输出: 3
解释: 最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。
示例 2:

输入: [2,2,2,2,2]
输出: 1
解释: 最长连续递增序列是 [2], 长度为1。
注意：数组长度不会超过10000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int findLengthOfLCIS(int* nums, int numsSize)
{
    int res = 0;
    int max = 0;

    if(numsSize == 1)
        return 1;
    if(numsSize == 0 || nums == NULL)
        return 0;
    for(int i = 1; i < numsSize; i++)
    {
        if(nums[i] > nums[i - 1])
        {
            res++;
            if(res > max)
                max = res;
        }
        else
        {
            res = 0;
        }
    }
    return max + 1;
}

int main(void)
{
    int a1[] = {1, 3, 5, 4, 7};
    int a2[] = {2, 2, 2, 2, 2};
    int a3[] = {1, 3, 5, 7};
    printf("%d\n", findLengthOfLCIS(a1, sizeof(a1) / sizeof(int)));
    printf("%d\n", findLengthOfLCIS(a2, sizeof(a2) / sizeof(int)));
    printf("%d\n", findLengthOfLCIS(a3, sizeof(a3) / sizeof(int)));
    return 0;
}
