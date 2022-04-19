/*
https://leetcode-cn.com/problems/binary-prefix-divisible-by-5

给定由若干 0 和 1 组成的数组 A。我们定义 N_i：从 A[0] 到 A[i] 的第 i 个子数组被解释为一个二进制数（从最高有效位到最低有效位）。
返回布尔值列表 answer，只有当 N_i 可以被 5 整除时，答案 answer[i] 为 true，否则为 false。
 
示例 1：
输入：[0,1,1]
输出：[true,false,false]
解释：
输入数字为 0, 01, 011；也就是十进制中的 0, 1, 3 。只有第一个数可以被 5 整除，因此 answer[0] 为真。
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

bool* prefixesDivBy5(int* A, int ASize, int* returnSize) {
	unsigned int var = 0;
	bool * r = (bool *)malloc(sizeof(bool) * ASize);

	*returnSize = ASize;

	for(size_t i = 0; i < ASize; i++)
	{
		
		var |= ( (unsigned int)(*(A+i)) ) << i;

		if((var % 5) == 0)
			*(r+i) = true;
		else
			*(r+i) = false;
	}
	return r;
}

int main()
{
	int A[] = {1,0,0,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,1,0,0,0,0,1,1,0,1,0,0,0,1 };
	int returnSize;
	bool * r = prefixesDivBy5(A, sizeof(A)/4, &returnSize);

	for (size_t i = 0; i < returnSize; i++)
	{
		if( *(r+i) )
			printf("true\n");
		else
			printf("false\n");
	}

}