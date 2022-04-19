/*
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
示例 1:

输入: [ [1,2], [2,3], [3,4], [1,3] ]

输出: 1

解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:

输入: [ [1,2], [1,2], [1,2] ]

输出: 2

解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
示例 3:

输入: [ [1,2], [2,3] ]

输出: 0

解释: 你不需要移除任何区间，因为它们已经是无重叠的了。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/non-overlapping-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
选择的区间结尾越小，余留给其它区间的空间就越大，就越能保留更多的区间。
因此，我们采取的贪心策略为，优先保留结尾小且不相交的区间
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        if(intervals.empty())
            return 0;

        int n = intervals.size();

        // 先把区间按照结尾的大小进行增序排序
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) { return a[1] < b[1]; });

        int total = 0, prev = intervals[0][1];

        // 每次选择结尾最小且和前一个选择的区间不重叠的区间
        for(int i = 1; i < n; i++)
        {
            if(intervals[i][0] < prev)  // 区间有重叠部分
                total++;
            else
                prev = intervals[i][1];
        }
        return total;
    }
};

int main(int argc, char* argv[])
{
    Solution            s;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << s.eraseOverlapIntervals(intervals) << endl;
    return 0;
}

