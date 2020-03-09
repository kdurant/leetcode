/*
https://leetcode-cn.com/problems/power-of-three/

给定一个整数，写一个函数来判断它是否是 3 的幂次方。

示例 1:

输入: 27
输出: true
示例 2:

输入: 0
输出: false
示例 3:

输入: 9
输出: true
示例 4:

输入: 45
输出: false
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

bool isPowerOfThree(int n) {
    if(n <= 0)
		return false;

	if( n== 1)
		return true;
	
	while( (n%3) == 0 )
	{
		if(n == 3)
			return true;
		else
			n /= 3;
	}
	return false;
}

int main()
{
	if(isPowerOfThree(59049))
		printf("success\n");
	else
		printf("failed\n");
}