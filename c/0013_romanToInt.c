/*
https://leetcode-cn.com/problems/roman-to-integer/
*/
#include <stdio.h>
#include <string.h>

int romanToInt(char * s){
    int result = 0;
    int len = strlen(s);
    char *t;
    for(t = s+len-1; len > 0; len--, t--)
    {
        switch (*t)
        {
        case 'I':
            if(*(t+1) == '\0')
                result += 1;
            else if(*(t+1) == 'V')
                result -= 1;
            else if(*(t+1) == 'X')
                result -= 1;
            else
                result += 1;
            break;
        case 'V':
            result += 5;
            break;
        case 'X':
            if(*(t+1) == '\0')
                result += 10;
            else if(*(t+1) == 'L')
                result -= 10;
            else if(*(t+1) == 'C')
                result -= 10;
            else
                result += 10;
            break;
        case 'L':
            result += 50;
            break;
        case 'C':
            if(*(t+1) == '\0')
                result += 100;
            else if(*(t+1) == 'D')
                result -= 100;
            else if(*(t+1) == 'M')
                result -= 100;
            else
                result += 100;
            break;
            break;
        case 'D':
            result += 500;
            break;
        case 'M':
            result += 1000;
            break;
        
        default:
            break;
        }
    }
    return result;
}


int main()
{
    printf("%d\n", romanToInt("MCMXCIV"));
}