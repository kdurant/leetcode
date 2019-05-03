/*
https://leetcode-cn.com/problems/add-digits/

给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。

示例:

输入: 38
输出: 2 
解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。
进阶:
你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

int addDigits(int num){
	int result = 0;
	if(num < 10)
		return num;
	
	while(num)
	{
		result += (num % 10);
		num /= 10;
	}
	
	return addDigits(result);
}




int main()
{
	printf("%d\n", addDigits(38));
    return 0;
}