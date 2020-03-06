/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
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
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;

        // 先排序
        sort(nums.begin(), nums.end());
        for(int m = 0; m < nums.size(); m++)
        {
            int l = m + 1;
            int r = nums.size() - 1;
            // 排序后的数组相邻2个元素相等，则不查找
            if(nums[m] == nums[m - 1])
                continue;
            while(l < r)
            {
                if(nums[m] + nums[l] + nums[r] == 0)
                {
                    res.push_back({nums[m], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l + 1])
                        l++;
                    while(l < r && nums[r] == nums[r - 1])
                        r--;
                    l++;
                    r--;
                }
                else if(nums[m] + nums[l] + nums[r] > 0)
                    r--;
                else
                    l++;
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    vector<int>         nums = {-1, 0, 1, 2, -1, -4};
    Solution            s;
    vector<vector<int>> res;
    res = s.threeSum(nums);

    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << endl;

    return 0;
}
