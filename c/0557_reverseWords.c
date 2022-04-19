/*
https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/

给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * reverseWords(char * s){
    int len = strlen(s)+1;
    char *r = malloc(len);
    int index = 0;
    char *start = s;
    char *end;
    if(len == 1)
        return s;
    
    if(len == 2)
        return s;

//"Let's take LeetCode contest"
    for(int i = 0; i < len; i++, s++)
    {
        if( (*s == ' ') || (*s == '\0') )
        {
            for (end = s-1; end >= start; end--)
            {
                r[index++] = *end;
            }
            r[index++] = (*s == ' ') ? ' ': '\0';
            start = s+1 ;
        }
    }
    return r;
}

int main()
{

    char *s = "";
    printf("%s\n", reverseWords(s));
    
    return 0;
} 