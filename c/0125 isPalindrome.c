/*
https://leetcode-cn.com/problems/valid-palindrome/

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


bool isPalindrome(char * s){
    if(s == NULL)
        return true;

    char *start =s;
    char *end = s + strlen(s) -1;
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
            if((*start == *end))
                start++, end--;
            else
                return false;
        }
        else 
        {
            if((*start == *end) || (*start == *end -0x20) || (*start == *end + 0x20) )
            {
                start++, end--;
            }
            else
                return false;
        }
        
    }
    return true;
}



int main()
{
    char name[] = "race a car";
    char typed[] = "ppyypllr";
    printf("%d\n", isPalindrome(name));
}