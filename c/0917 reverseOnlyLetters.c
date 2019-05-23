/*
https://leetcode-cn.com/problems/reverse-only-letters/

给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

 

示例 1：

输入："ab-cd"
输出："dc-ba"
示例 2：

输入："a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"
示例 3：

输入："Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"
 

提示：

S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S 中不包含 \ or "

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char * reverseOnlyLetters(char * S){
    char *save = S;
    char *start = S;
    char *end = S + strlen(S) - 1;
    char ch;
    while(start <= end)
    {
        if( isalpha(*start) && isalpha(*end) ) // 如果都是字符，交换他们
        {
            ch = *start;
            *start = *end;
            *end = ch;
            
            start++;
            end--;
        }
        else
        {
            if(!isalpha(*start))
                start++;
            if(!isalpha(*end))
                end--;
        }
    }
    return save;
}

int main()
{
    char num1[] = "a-bC-dEf-ghIj";
    printf("%s\n", reverseOnlyLetters(num1));
}