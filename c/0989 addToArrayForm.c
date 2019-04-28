/* 
https://leetcode-cn.com/problems/add-to-array-form-of-integer/ 
还未完成
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
	unsigned char carry_flag = 0;
	int *result = (int*)malloc(sizeof(int)*(ASize + 1));

	for (size_t i = ASize - 1; i >= 0; i--)
	{
		*(result + i + 1) = (*(A + i) + (K % 10) + carry_flag)%10;

		if (*(A + i) + (K % 10) + carry_flag >= 10)
		{
			carry_flag = 1;
		}
		else
		{
			carry_flag = 0;
		}

		K = K / 10;

		if (i == 0)
		{
			if (carry_flag)
			{
				*result = 1;
				*returnSize = ASize + 1;
				return result;
			}

			else
			{
				*returnSize = ASize;
				return result + 1;
			}
		}
	}

}

int main()
{
	int A[10] = { 9,9,9,9,9,9,9,9,9,9 };
	int K = 1;
	int returnSize;
	int * r = addToArrayForm(A, 10, K, &returnSize);

	for (size_t i = 0; i < returnSize; i++)
	{
		printf("%d\n", r[i]);
	}

}