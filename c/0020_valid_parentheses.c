/*
https://leetcode-cn.com/problems/valid-parentheses/

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true

*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

bool isValid(char* s) 
{  
    int top = 0;
    char *stack = malloc(strlen(s) + 1);

    while(*s != '\0')
    {
        if( (*s == '(') || (*s == '{') || (*s == '[') )
        {
            stack[top++] = *s;
        }
        else
        {
            switch(*s)
            {
                case ')':
                    if(top)
                    {
                        if(stack[top-1] == '(')
                            top--;
                        else
                            return false;
                    }
                    else 
                        return false;
                    break;

                case ']':
                    if(top)
                    {
                        if(stack[top-1] == '[')
                            top--;
                        else
                            return false;
                    }
                    else 
                        return false;
                    break;
                case '}':
                    if(top)
                    {
                        if(stack[top-1] == '{')
                            top--;
                        else
                            return false;
                    }
                    else 
                        return false;
                    break;
                default:
                    break;
            }
        }
        s++;
    }
    return top == 0;
}

int main()
{
    char * s = "[";
    printf("%d\n", isValid(s));
    return 0;
}
