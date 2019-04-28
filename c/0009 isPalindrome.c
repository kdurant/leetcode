/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include<limits.h>

/**
 * @brief 0是回文.  负数和个位数是0的不是可能是回文
 * 
 * @param x 
 * @return true 
 * @return false 
 */
bool isPalindrome(int x) 
{
    int pop;
    int result = 0;
    if(x == 0)
        return true;

    if(x < 0 || x%10 == 0)
        return false;

    //将原始数字除以 10，然后给反转后的数字乘上 10，所以，当原始数字小于反转后的数字时，就意味着我们已经处理了一半位数的数字。
    while(x > result)
    {
        pop = x % 10;
        x = x/10;

        result = result * 10 + pop;
    }
    if(result == x || result/10 == x)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    if(isPalindrome(10))
        printf("true\n");
    
    else
        printf("false\n");
    
    return 0;
}
