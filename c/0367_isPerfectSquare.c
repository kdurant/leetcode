/*
https://leetcode-cn.com/problems/valid-perfect-square/

给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。

说明：不要使用任何内置的库函数，如  sqrt。

示例 1：

输入：16
输出：True
示例 2：

输入：14
输出：False
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

// 利用 1+3+5+7+9+…+(2n-1)=n^2，即完全平方数肯定是前n个连续奇数的和
bool isPerfectSquare(int num){
	for(int i = 1; num > 0; i += 2)
		num -= i;
	return 0 == num;	
}
 

int main()
{

	
	if(isPerfectSquare(4))
		printf("true\n");
	else 
		printf("false\n");

}