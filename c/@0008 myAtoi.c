#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

int myAtoi(char* str)
{
    int  idx       = 0;
    char num[1000] = {0};

    long long ret   = 0;
    long long scale = 1;

    while(*str)
    {
        if(*str == ' ')
            ;
        else if(*str == '+' || *str == '-')
        {
            if(idx >= 1 && (num[idx - 1] == '+' || num[idx - 1] == '-'))
                return 0;
            else
                num[idx++] = *str;
        }
        else if(*str >= '0' && *str <= '9')
            num[idx++] = *str;
        else
            break;
        str++;
    }

    while(idx - 1 >= 0)
    {
        if(num[idx - 1] != '+' && num[idx - 1] != '-')
        {
            ret += (num[idx - 1] - '0') * scale;
            scale *= 10;
            if(ret - 1 > INT_MAX || scale / 100 > INT_MAX)
                break;
        }
        idx--;
    }
    if(num[0] == '+')
        ;
    else if(num[0] == '-')
        ret = 0 - ret;

    if(ret > INT_MAX)
        return INT_MAX;
    else if(ret < INT_MIN)
        return INT_MIN;
    else
        return ret;
}

int main(void)
{
    printf("%d\n", myAtoi("+-2"));
    printf("%d\n", myAtoi(" +0 123"));
    printf("%d\n", myAtoi("42"));
    printf("%d\n", myAtoi("   -42"));
    printf("%d\n", myAtoi("4193 with words"));
    printf("%d\n", myAtoi("words and 987"));
    printf("%d\n", myAtoi("-91283472332"));
    printf("%d\n", myAtoi("  0000000000000000000000000000000000000012345678"));

    assert(myAtoi("+-2") == 0);
    assert(myAtoi("42") == 42);
    assert(myAtoi("   -42") == -42);
    assert(myAtoi("4193 with words") == 4193);
    assert(myAtoi("words and 987") == 0);
    assert(myAtoi("-91283472332") == INT_MIN);
    assert(myAtoi("  0000000000000000000000000000000000000012345678") == 12345678);

    return 0;
}
