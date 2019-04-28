/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
注意:
假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
*/
#include <stdio.h>
#include <stdint.h>

#include<limits.h>

/**
 * @brief 假设要翻转数据为1234
 * 1234%10, 得到个位数, 1234/10得到123
 * @param x 
 * @return int 
 */
int reverse(int x) {
{
    int pop;
    int result;
    while(x != 0)
    {
        pop = x%10;
        x = x/10;

        if( (result > INT_MAX/10) || (result < INT_MIN/10) )
            return 0;

        result = result*10 + pop;

    }
    return result;
}

int main()
{
    printf("%d\n", reverse_integer(1534236469));
    return 0;
}