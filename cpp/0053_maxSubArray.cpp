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
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result   = INT_MIN;
        int numsSize = int(nums.size());
        // dp[i]表示nums中以nums[i]结尾的最大子序和
        vector<int> dp(numsSize);
        dp[0]  = nums[0];
        result = dp[0];
        for(int i = 1; i < numsSize; i++)
        {
            dp[i]  = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }

        return result;
    }
};

int main(void)
{
    Solution    s;
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(nums) << endl;

    return 0;
}
