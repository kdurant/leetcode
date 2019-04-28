/*
https://leetcode-cn.com/problems/self-dividing-numbers/

自除数 是指可以被它包含的每一位数除尽的数。

例如，128 是一个自除数，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。

还有，自除数不允许包含 0 。

给定上边界和下边界数字，输出一个列表，列表的元素是边界（含边界）内所有的自除数。

示例 1：

输入： 
上边界left = 1, 下边界right = 22
输出： [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
注意：

每个输入参数的边界满足 1 <= left <= right <= 10000。
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

int* selfDividingNumbers(int left, int right, int* returnSize){
	int * r = malloc(sizeof(int) * (right-left));

	int tmp = 0;
	uint8_t flag = 0;
	int len = 0;
	int data;
	for (size_t i = left; i <= right; i++)
	{
		data = i;
		//while ( (left % 10 == 0) && (left / 10 == 0) )
		while (data)
		{
			tmp = data % 10;
			if (tmp == 0)
			{
				flag = 0;
				break;
			}
			
			if(i % tmp == 0)
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
			data = data / 10;
			if (data == 0)
				break;
			if ((i % 10 == 0) && (i / 10 == 0))
			{
				break;
			}
		}
		if(flag == 1)
		{
			flag = 0;
			r[len] = i;
			len++;
		}

	}
	*returnSize = len;
	return r;	
}



int main()
{
	// int A[] = {1,2,2,1 };
	// int B[] = {2,2};
	// int returnSize;
	// int * r = intersection(A, sizeof(A)/4, B, sizeof(B)/4, &returnSize);

	// char *s = "";

	// printf("%d\n", bitwiseComplement(7));

	int returnSize;
	int * r = selfDividingNumbers(1, 10000, &returnSize);
	for (size_t i = 0; i < returnSize; i++)
	{
		printf("%d\n", r[i]);
	}
	
}