/*
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pascals-triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        vector<int>         row;
        int                 col = 0;
        if(numRows == 0)
            return {};
        else if(numRows == 1)
            res.push_back({1});
        else
        {
            for(int i = 0; i < numRows; i++)
            {
                if(i == 0)
                {
                    res.push_back({1});
                    continue;
                }
                col = i + 1;
                for(int j = 0; j < col; j++)
                {
                    if(j == 0)
                        row.push_back(res[i - 1][0]);
                    else if(j == col - 1)
                        row.push_back(res[i - 1][i - 1]);
                    else
                        row.push_back(res[i - 1][j - 1] + res[i - 1][j]);
                }
                res.push_back(row);
                row.clear();
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    s.generate(5);

    return 0;
}
