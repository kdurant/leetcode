/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxSubArray(int* nums, int numsSize)
{
    int* dp = malloc(sizeof(int) * (numsSize + 1));
    dp[0]   = nums[0];

    int max = dp[0];
    for(size_t i = 1; i < numsSize; i++)
    {
        if(dp[i - 1] > 0)
            dp[i] = dp[i - 1] + nums[i];
        else
            dp[i] = nums[i];

        if(dp[i] >= max)
            max = dp[i];
    }
    return max;
}

int main()
{
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("%d\n", maxSubArray(A, sizeof(A) / 4));
}