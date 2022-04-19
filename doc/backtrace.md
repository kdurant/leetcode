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

# [46 全排列](https://leetcode-cn.com/problems/permutations/)
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

# [78 子集](https://leetcode-cn.com/problems/subsets/)
```cpp
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
```