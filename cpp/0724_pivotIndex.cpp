/*
给你一个整数数组 nums ，请计算数组的 中心下标 。

数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。

如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。

如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 -1 。

 

示例 1：

输入：nums = [1, 7, 3, 6, 5, 6]
输出：3
解释：
中心下标是 3 。
左侧数之和 sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 ，
右侧数之和 sum = nums[4] + nums[5] = 5 + 6 = 11 ，二者相等。
示例 2：

输入：nums = [1, 2, 3]
输出：-1
解释：
数组中不存在满足此条件的中心下标。
示例 3：

输入：nums = [2, 1, -1]
输出：0
解释：
中心下标是 0 。
左侧数之和 sum = 0 ，（下标 0 左侧不存在元素），
右侧数之和 sum = nums[1] + nums[2] = 1 + -1 = 0 。
 

提示：

1 <= nums.length <= 104
-1000 <= nums[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-pivot-index
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int>& nums)
    {
        // vector 累加和
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum   = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(2 * sum + nums[i] == total)
                return i;

            sum += nums[i];
        }
        return -1;
    }
};

int main(int argc, char* argv[])
{
    Solution    s;
    vector<int> v{1, 7, 3, 6, 5, 6};
    cout << s.pivotIndex(v) << "\n";
    return 0;
}
