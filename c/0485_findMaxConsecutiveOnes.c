/*
https://leetcode-cn.com/problems/max-consecutive-ones/

给定一个二进制数组， 计算其中最大连续1的个数。

示例 1:

输入: [1,1,0,1,1,1]
输出: 3
解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int findMaxConsecutiveOnes(int* nums, int numsSize){
	int last = 0;
	int cur = 0;
	for (size_t i = 0; i < numsSize; i++)
	{
		if(nums[i] == 1)
			cur++;
		
		if( (nums[i] == 0) || ( i == numsSize -1))
		{
			if(cur > last)
				last = cur;
			cur = 0;
		}
	}
	return last;
}


int main()
{
	
	int A[] = {1,1,0,1,1,1};
	printf("%d\n", findMaxConsecutiveOnes(A, sizeof(A)/4));
	return 0 ;
}