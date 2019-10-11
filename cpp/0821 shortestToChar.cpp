/*
给定一个字符串 S 和一个字符 C。返回一个代表字符串 S 中每个字符到字符串 S 中的字符 C 的最短距离的数组。

示例 1:

输入: S = "loveleetcode", C = 'e'
输出: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
说明:

字符串 S 的长度范围为 [1, 10000]。
C 是一个单字符，且保证是字符串 S 里的字符。
S 和 C 中的所有字母均为小写字母。
在真实的面试中遇到过这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-distance-to-a-character
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
public:
    vector<int> shortestToChar(string S, char C)
    {
        int n = S.size();

        vector<int> res(n, n);

        for(int i{0}; i < n; ++i)
        {
            //如果当前字符是C
            if(S[i] == C)
            {
                res[i] = 0;
                continue;
            }

            // 向右查找
            int j = i + 1;
            while(j < n && S[j] != C)
            {
                ++j;
            }
            if(j < n)  // 保存距离
                res[i] = j - i;
            j = i - 1;
            // 向左查找
            while(j >= 0 && S[j] != C)
            {
                --j;
            }
            if(j >= 0)
                res[i] = min(res[i], i - j);
        }
        return res;
    }
};

int main()
{
    Solution    s;
    vector<int> ans = s.shortestToChar("loveleetcode", 'e');

    int *data = ans.data();
    for(int i = 0; i < ans.size(); i++)
        cout << *(data + i) << "\t";

    return 0;
}
