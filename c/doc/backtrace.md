什么是回溯算法？
回溯法是一种系统搜索问题解空间的方法。为了实现回溯，需要给问题定义一个解空间。
说到底它是一种搜索算法。只是这里的搜索是在一个叫做解空间的地方搜索。

# 算法框架
```python
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```

# [全排列](https://leetcode-cn.com/problems/permutations/)
[思路](https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-xiang-jie-by-labuladong-2/)
```cpp
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
```

# [组合](https://leetcode-cn.com/problems/combinations/)

# [子集](https://leetcode-cn.com/problems/subsets/)
