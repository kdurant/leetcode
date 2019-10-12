/*
给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold Medal", "Silver Medal",
"Bronze Medal"）。

(注：分数越高的选手，排名越靠前。)

示例 1:

输入: [5, 4, 3, 2, 1]
输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal" and "Bronze Medal").
余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
提示:

N 是一个正整数并且不会超过 10000。
所有运动员的成绩都不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/relative-ranks
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
    vector<string> findRelativeRanks(vector<int>& nums)
    {
        map<int, string> check_maps;
        vector<int>      nums_after_sort = nums;
        sort(nums_after_sort.begin(), nums_after_sort.end());
        reverse(nums_after_sort.begin(), nums_after_sort.end());

        // 已经从大到小排好序
        // 排序好的数组内容最为key
        for(int i = 0; i < nums_after_sort.size(); i++)
        {
            if(i == 0)
            {
                check_maps[nums_after_sort[i]] = "Gold Medal";
            }
            else if(i == 1)
            {
                check_maps[nums_after_sort[i]] = "Silver Medal";
            }
            else if(i == 2)
            {
                check_maps[nums_after_sort[i]] = "Bronze Medal";
            }
            else
                check_maps[nums_after_sort[i]] = to_string(i + 1);
        }

        vector<string> res(nums.size());
        for(int index = 0; index < nums.size(); index++)
        {
            res[index] = check_maps[nums[index]];
        }
        return res;
    }
};

int main(void)
{
    vector<int>    nums{1, 4, 3, 2, 5};
    vector<string> res;
    Solution       sol;

    res = sol.findRelativeRanks(nums);

    for(auto i : res)
        cout << i << endl;

    return 0;
}
