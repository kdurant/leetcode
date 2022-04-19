/*
https://leetcode-cn.com/problems/intersection-of-two-arrays/submissions/

给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]
说明:

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	int * r;
	int len = 0;
	uint8_t flag = 0;  // 交集中是否已经有相同的数

	if(nums1Size >= nums2Size)
		r = malloc(sizeof(int) * nums2Size);
	else
		r = malloc(sizeof(int) * nums2Size);
	
	for (size_t i = 0; i < nums1Size; i++)
	{
		for (size_t j = 0; j < nums2Size; j++)
		{
			if(nums2[j] == nums1[i])
			{
				if(len == 0)  // 第一次直接写入
				{
					r[len++] = nums1[i];
				}
				else
				{
					// 如果两个数组里的数相等, 还要判断交集里是否已经存放这个数据
					for (size_t k = 0; k < len; k++)
					{
						if(nums1[i] == r[k])
							flag = 1;
					}
					
					if(flag == 0)
						r[len++] = nums1[i];
					else
						flag = 0;
				}
			}
		}
		
	}
	*returnSize = len;
	return r;
}

int main()
{
	int A[] = {1,2,2,1 };
	int B[] = {2,2};
	int returnSize;
	int * r = intersection(A, sizeof(A)/4, B, sizeof(B)/4, &returnSize);

	for (size_t i = 0; i < returnSize; i++)
	{
		printf("%d\n", r[i]);
	}

}