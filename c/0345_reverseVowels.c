/*
https://leetcode-cn.com/problems/reverse-vowels-of-a-string/


编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1:

输入: "hello"
输出: "holle"
示例 2:

输入: "leetcode"
输出: "leotcede"
说明:
元音字母不包含字母"y"。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isvowel(char ch)
{
    if(
        (ch == 'a') ||  (ch == 'o') ||  (ch == 'e') ||  (ch == 'i') ||  (ch == 'u') ||
        (ch == 'A') ||  (ch == 'O') ||  (ch == 'E') ||  (ch == 'I') ||  (ch == 'U')
    )
        return true;
    else 
        return false;
}

char * reverseVowels(char * S){
    char *save = S;
    char *start = S;
    char *end = S + strlen(S) - 1;
    char ch;
    while(start <= end)
    {
        if( isvowel(*start) && isvowel(*end) ) // 如果都是字符，交换他们
        {
            ch = *start;
            *start = *end;
            *end = ch;
            
            start++;
            end--;
        }
        else
        {
            if(!isvowel(*start))
                start++;
            if(!isvowel(*end))
                end--;
        }
    }
    return save;
}

int main()
{
    char num1[] = "leetcode";
    printf("%s\n", reverseVowels(num1));
}