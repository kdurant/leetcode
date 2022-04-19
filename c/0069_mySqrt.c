/*
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842...,
     由于返回类型是整数，小数部分将被舍去。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sqrtx
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int mySqrt(int x)
{
    long long mid;
    long long res;
    int       left  = 0;
    int       right = x / 2 + 1;
    while(left <= right)
    {
        mid = left + (right - left) / 2;
        res = mid * mid;
        if(res == x)
            return mid;
        else if(res > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return right;
}

int main(void)
{
    printf("%d\n", mySqrt(2147395599));  // 4
    printf("%d\n", mySqrt(2));
    printf("%d\n", mySqrt(16));
    printf("%d\n", mySqrt(17));  // 3
    printf("%d\n", mySqrt(5));
    printf("%d\n", mySqrt(8));

    return 0;
}

