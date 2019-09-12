/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <limits.h>
char* longestCommonPrefix(char** strs, int strsSize)
{
    int  idx     = 0;
    int  min_len = strlen(strs[0]);
    char ch;
    char flag = true;

    for(int i = 0; i < strsSize; i++)
    {
        char* s   = strs[i];
        int   len = strlen(s);
        if(len < min_len)
            min_len = len;
    }
    char* r = calloc(min_len + 1, sizeof(char));

    for(int i = 0; i < min_len; i++)
    {
        ch = strs[0][i];
        if(ch == '\0')
            return r;

        flag = true;
        for(int j = 0; j < strsSize; j++)
        {
            if(strs[j][i] == '\0')
            {
                flag = false;
                break;
            }
            else if(strs[j][i] != ch)
            {
                flag = false;
                break;
            }
        }
        if(flag)
            r[idx++] = ch;
    }
    return r;
}

int main()
{
    char* str[3] = {"flower", "flow", "flight"};
    printf("%s\n", longestCommonPrefix(str, 3));
    return 0;
}