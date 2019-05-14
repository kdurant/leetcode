/*
https://leetcode-cn.com/problems/find-the-difference/

给定两个字符串 s 和 t，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。

 

示例:

输入：
s = "abcd"
t = "abcde"

输出：
e

解释：
'e' 是那个被添加的字母。
*/

#include <stdio.h>
#include <stdbool.h>

char findTheDifference(char * s, char * t){
    char r = 0;
    while(*s != '\0')
    {
        r ^= *s;
        s++;
    }
    while(*t != '\0')
    {
        r ^= *t;
        t++;
    }
    return r;
}


int main()
{
    printf("%c\n", findTheDifference("123", "1243"));
}