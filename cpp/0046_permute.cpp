/*
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        backtrack(nums, res, 0);
        return res;
    }

    void backtrack(vector<int> &nums, vector<vector<int>> &res, int i)
    {
        if(i == nums.size())
            res.push_back(nums);

        for(int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            backtrack(nums, res, i + 1);
            swap(nums[i], nums[j]);
        }
    }
};
int main(void)
{
    Solution            s;
    vector<int>         nums = {1, 2, 3};
    vector<vector<int>> ret;
    ret = s.permute(nums);

    for(int i = 0; i < ret.size(); i++)
    {
        for(int j = 0; j < ret[i].size(); j++)
        {
            cout << ret[i][j] << "\t";
        }
        cout << "\n";
    }
}