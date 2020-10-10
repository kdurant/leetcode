/*
给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

找到所有在 [1, n] 范围之间没有出现在数组中的数字。

您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

示例:

输入:
[4,3,2,7,8,2,3,1]

输出:
[5,6]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        for(int i = 0; i < nums.size(); ++i)
        {
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        }

        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0)
                res.push_back(i + 1);
        }
        return res;
    }
};

int main(void)
{
    Solution    sol;
    vector<int> v{4, 3, 2, 7, 8, 2, 3, 1};

    auto r = sol.findDisappearedNumbers(v);

    for(auto i : r)
        cout << i << "\t" << endl;

    return 0;
}
