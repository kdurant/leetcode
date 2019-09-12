/*
给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-strstr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>

int strStr(char* haystack, char* needle)
{
    if(*needle == '\0')
        return 0;

    char* h    = haystack;
    int   res  = 0;
    bool  flag = true;

    while(*h)
    {
        char* n = needle;
        if(*h == *n)
        {
            char* h1 = h;
            flag     = true;
            while(*n)
            {
                if(*n != *h1)
                {
                    flag = false;
                    break;
                }
                else if(*h1 == '\0')
                {
                    flag = false;
                    break;
                }
                else
                    n++, h1++;
            }
            if(flag)
                return res;
        }
        h++;
        res++;
    }
    return -1;
}

int main(void)
{
    // int nums[] = {3, 6, 1, 0};
    printf("%d\n", strStr("aaa", "aaaa"));   // -1
    printf("%d\n", strStr("", "a"));         // -1
    printf("%d\n", strStr("", ""));          // 0
    printf("%d\n", strStr("aaaaa", "bba"));  // -1
    return 0;
}

