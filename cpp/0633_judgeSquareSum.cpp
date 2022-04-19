/*
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。

 

示例 1：

输入：c = 5
输出：true
解释：1 * 1 + 2 * 2 = 5
示例 2：

输入：c = 3
输出：false
示例 3：

输入：c = 4
输出：true
示例 4：

输入：c = 2
输出：true
示例 5：

输入：c = 1
输出：true
 

提示：

0 <= c <= 231 - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-square-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <unordered_set>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        unsigned long int a = 0;
        unsigned long int b = (int)(sqrt(c));
        while(b >= a)
        {
            if(a * a + b * b > c)
                b--;
            else if(a * a + b * b < c)
                a++;
            else
                return true;
        }
        return false;
    }
};

int main(void)
{
    Solution s;
    cout << s.judgeSquareSum(20000) << endl;

    return 0;
}
