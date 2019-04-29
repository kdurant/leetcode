/*
https://leetcode-cn.com/problems/power-of-two/

给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:

输入: 1
输出: true
解释: 20 = 1
示例 2:

输入: 16
输出: true
解释: 24 = 16
示例 3:

输入: 218
输出: false
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

bool isPowerOfTwo(int n) {
	int r = 0;
	if(n < 0)
		return false;
	for(size_t i = 0; i < 32; i++)
	{
		r += (n>>i) & 0x01;
	}
	if (r == 1)
		return true;
	else
	{
		return false;
	}	
}

int main()
{
	if(isPowerOfTwo(-2147483648))
		printf("success\n");
	else
		printf("failed\n");
}