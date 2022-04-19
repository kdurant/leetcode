/*
和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。

现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。

示例 1:

输入: [1,3,2,2,5,2,3,7]
输出: 5
原因: 最长的和谐数组是：[3,2,2,2,3].
说明: 输入的数组长度最大不超过20,000.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-harmonious-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findLHS(vector<int>& nums)
    {
        map<int, int> hash;

        // 统计每个元素出现的次数
        for(auto n : nums)
        {
            hash[n]++;
        }

        int max = 0;
        for(auto key : hash)
        {
            // 下一个数出现的次数
            if(hash.count(key.first + 1) && max < key.second + hash[key.first + 1])
                max = key.second + hash[key.first + 1];
        }
        return max;
    }
};
int main(int argc, char* argv[])
{
    Solution    s;
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << s.findLHS(nums) << endl;

    return 0;
}
