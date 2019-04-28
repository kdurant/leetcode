/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
所有输入只包含小写字母 a-z 。
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include<limits.h>

char* longestCommonPrefix(char** strs, int strsSize) 
{
    char* str=(char*)malloc(128);
    memset(str,0,128);
    for(size_t i = 0; i < strsSize; i++)
    {
        if (strs[i] == NULL)
            return NULL; 
    }
    
    for(size_t i = 0; i < 100; i++)
    {
        if(i == 0)
        {
            if( (strs[0][0] == strs[1][0]) && (strs[0][0] == strs[2][0]) )
            {
                str[i] = strs[0][0];
            }
            else
                break;
        }
        else
        {
            if( (strs[0][i] == strs[1][i]) && (strs[0][i] == strs[2][i]) )
            {
                str[i] = strs[0][i];
            }
            else 
            {
                str[i] = '\0';
                break;
            }
        }
    }
    return str;
}

int main()
{
    char *str[3] = {"flower","flow","flight"};
    printf("%s\n", longestCommonPrefix(str, 3));
    return 0;
}