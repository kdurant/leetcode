/*
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-intervals
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
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        if(intervals.size() == 0)
            return {};
        if(intervals.size() == 1)
            return intervals;

        int                 i;
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end());
        vector<int> prev = intervals[0];
        int         flag = 0;
        for(i = 0; i < intervals.size() - 1; i++)
        {
            // [1,  5],  [3, 8]
            if(prev[1] >= intervals[i + 1][0])
                prev[1] = max(prev[1], intervals[i + 1][1]), flag = 1;
            // [1, 4], [0, 4]
            if(prev[0] >= intervals[i + 1][0])
                prev[0] = intervals[i + 1][0], flag = 1;

            if(flag)  //
            {
                ret.push_back(prev);
                i++;
                flag = 0;
            }
            else
            {
                if(i == intervals.size() - 2)
                {
                    ret.push_back(intervals[i]);
                    ret.push_back(intervals[i + 1]);
                }
                else
                {
                    ret.push_back(prev);
                    prev = intervals[i + 1];
                }
            }
        }
        return ret;
    }
};

int main(void)
{
    Solution sol;
    // vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // vector<vector<int>> intervals = {{1, 4}, {5, 11}, {12, 18}};
    // vector<vector<int>> intervals = {{1, 4}, {4, 5}};
    // vector<vector<int>> intervals = {{1, 4}, {0, 4}};
    // vector<vector<int>> intervals = {{1, 4}, {0, 0}};
    vector<vector<int>> intervals = {{1, 4}, {0, 2}, {3, 5}};  //[0, 5]
    vector<vector<int>> ret;

    ret = sol.merge(intervals);

    for(int i = 0; i < ret.size(); i++)
    {
        cout << ret[i][0] << '\t' << ret[i][1] << endl;
    }

    return 0;
}
