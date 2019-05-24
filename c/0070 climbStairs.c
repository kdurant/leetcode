/*
https://leetcode-cn.com/problems/climbing-stairs/

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int climbStairs(int n){
    if(n < 0)
        return -1;
    
    int *res = malloc(sizeof(int)* (n+1));
    res[0] = 1;
    res[1] = 2;
    for (size_t i = 2; i < n; i++)
    {
        res[i] = res[i-1] + res[i-2];
    }
    return res[n-1]; 
}

int main()
{
    printf("%d\n", climbStairs(3));
}