/*
给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。如果剩余少于 k 个字符，则将剩余的所有全部反转。如果有小于 2k
但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。

示例:

输入: s = "abcdefg", k = 2
输出: "bacdfeg"
要求:

该字符串只包含小写的英文字母。
给定字符串的长度和 k 在[1, 10000]范围内。
在真实的面试中遇到过这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-string-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void reverseString2(char* s, int sSize)
{
    int i = 0;
    int j = sSize - 1;
    int tmp;
    while(i < j)
    {
        tmp  = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}

char* reverseStr(char* s, int k)
{
    int len = strlen(s);
    int idx = 0;
    while(len > 0)
    {
        if(len > 2 * k)  // 反转前面k个字符
        {
            reverseString2(s + idx, k);
            len -= 2 * k;
            idx += 2 * k;
        }
        else if(len < k)  // 全部反转
        {
            reverseString2(s + idx, len);
            len -= k;
            idx += k;
        }
        else
        {
            reverseString2(s + idx, k);
            len -= 2 * k;
            idx += 2 * k;
        }
    }
    return s;
}
int main(void)
{
    char s[] = "abcdefg";
    printf("%s\n", reverseStr(s, 2));
    return 0;
}
