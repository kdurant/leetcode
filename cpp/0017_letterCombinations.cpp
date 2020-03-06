/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

using namespace std;

class Solution
{
private:
    vector<string> res;
    const string   letterMap[10] = {" ",  // 0
                                  "",    "abc",  "def",
                                  "ghi",  // 4
                                  "jkl",  // 5
                                  "mno", "pqrs",
                                  "tuv",  // 8
                                  "wxyz"};

    void findCombination(const string &digits, int index, const string &s)
    {
        if(index == digits.size())
        {
            res.push_back(s);
            return;
        }
        char c = digits[index];
        assert(c >= '0' && c <= '9' && c != '1');
        string letters = letterMap[c - '0'];
        for(int i = 0; i < letters.size(); i++)
        {
            findCombination(digits, index + 1, s + letters[i]);
        }
        return;
    }

public:
    vector<string> letterCombinations(string digits)
    {
        res.clear();
        if(digits == "")
            return res;
        findCombination(digits, 0, "");
        return res;
    }
};

int main()
{
    Solution       s;
    vector<string> res;
    res = s.letterCombinations("234");
    for(size_t i = 0; i < res.size(); i++)
    {
        cout << i << "\t" << res[i] << endl;
    }

    return 0;
}