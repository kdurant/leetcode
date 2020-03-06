/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
private:
    void generate(int i, vector<int>& nums, vector<int>& item, vector<vector<int>>& res)
    {
        if(i == nums.size())
            return;

        item.push_back(nums[i]);
        res.push_back(item);
        generate(i + 1, nums, item, res);
        item.pop_back();
        generate(i + 1, nums, item, res);
    }

public:
    /**
     * @brief 回溯算法
     *
     * @param nums
     * @return vector<vector<int>>
     */
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int>         item;
        res.push_back(item);
        generate(0, nums, item, res);
        return res;
    }

    /**
     * @brief 使用位运算解决问题
     *
     * @param nums
     * @return vector<vector<int>>
     */
    vector<vector<int>> subsets1(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int>         item;

        int size = pow(2, nums.size());

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if((i & (1 << j)) & (1 << j))
                {
                    item.push_back(nums[j]);
                }
            }
            res.push_back(item);
            item.clear();
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution            s;
    vector<int>         nums = {1, 2, 3, 4};
    vector<vector<int>> res;

    res = s.subsets(nums);

    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}
