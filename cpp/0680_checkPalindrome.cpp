/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:

输入: "aba"
输出: True
示例 2:

输入: "abca"
输出: True
解释: 你可以删除c字符。
注意:

字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome-ii
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
    bool checkPalindrome(string s)
    {
        int size = s.length();
        int l = 0, r = size - 1;

        while(l <= r)
        {
            if(s[l] != s[r])
                return false;
            else
                l++, r--;
        }
        return true;
    }

    bool validPalindrome(string s)
    {
        int size = s.length();

        int l = 0, r = size - 1;

        while(l <= r)
        {
            if(s[l] != s[r])
            {
                return this->checkPalindrome(s.substr(l, r - l)) || this->checkPalindrome(s.substr(l + 1, r - l));
            }
            else
                l++, r--;
        }
        return true;
    }
};

int main(void)
{
    Solution s;
    cout << s.validPalindrome("aba") << endl;                    // true
    cout << s.validPalindrome("abca") << endl;                   // true
    cout << s.validPalindrome("abc") << endl;                    // flase
    cout << s.validPalindrome("ebcbbececabbacecbbcbe") << endl;  // true
    cout << s.validPalindrome("bddb") << endl;                   // true

    return 0;
}

