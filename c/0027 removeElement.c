/*
https://leetcode-cn.com/problems/remove-element/

给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int removeElement(int* nums, int numsSize, int val){
	int i = 0;
    if(numsSize == 0)
		return 0;

	while(numsSize)
	{
		if(nums[i] == val)
		{
			for (size_t j = i; j < numsSize + i -1; j++)
			{
				nums[j] = nums[j+1];
			}
		}
		else
		{
			i++;
		}
		numsSize--;
	}
	return i;
}

int main()
{
	int A[] = {4,3,2,1};
	
	printf("%d\n", removeElement(A, sizeof(A)/4, 2));
	return 0 ;
}