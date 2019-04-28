/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

int* twoSum(int* nums, int numsSize, int target) {

	int *result = (int *)malloc(sizeof(int)*2);

	for(size_t i = 0; i < numsSize-1; i++)
	{
		for(size_t j = i+1; j < numsSize; j++)
		{
			if(*(nums + i) + *(nums+j) == target)
			{
				result[0] = i;
				result[1] = j;
				// *(result+1) = j;
				return result;
			}

		}
		
	}
	return result;
}

int main()
{
	int nums[4] = {2, 7, 11, 15};
	int *result;
	result = twoSum(nums, 4, 17);
    
	printf("first index is %d\n", *result);
	printf("second index is %d\n", *(result+1));

    return 0;
} 