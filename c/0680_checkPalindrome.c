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

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isPalindrome(char *start, char *end)
{
    if(start == end)
        return true;

    while(start <= end)
    {
        if(!isalpha(*start) && !isdigit(*start))
        {
            start++;
            continue;
        }
        if(!isalpha(*end) && !isdigit(*end))
        {
            end--;
            continue;
        }
        if(isdigit(*start))
        {
            if(*start == *end)
                start++, end--;
            else
                return false;
        }
        else
        {
            if((*start == *end) || (*start == *end - 0x20) || (*start == *end + 0x20))
            {
                start++, end--;
            }
            else
                return false;
        }
    }
    return true;
}

bool validPalindrome(char *s)
{
    if(s == NULL)
        return true;

    char *start = s;
    char *end   = s + strlen(s) - 1;
    int delete  = 0;
    while(start <= end)
    {
        if(*start != *end)
        {
            return isPalindrome(start, end - 1) || (isPalindrome(start + 1, end));
        }
        {
            start++;
            end--;
        }
    }
    return true;
}
int main(void)
{
    printf("%d\n", validPalindrome("aba"));
    printf("%d\n", validPalindrome("abca"));
    printf("%d\n", validPalindrome("abc"));
    printf("%d\n", validPalindrome("ebcbbececabbacecbbcbe"));
    printf("%d\n", validPalindrome("bddb"));

    return 0;
}
