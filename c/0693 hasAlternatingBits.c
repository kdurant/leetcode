/*
https://leetcode-cn.com/problems/binary-number-with-alternating-bits/submissions/
给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

bool hasAlternatingBits(int n){
	while (n)
	{
		if( (n & 0x01 ) == ((n & 0x02) >> 1) )
		{
			return false;
		}
		n = n >> 1;
		if(n == 0)
			break;
		
	}
	return true;
	
}



int main()
{
	// int A[] = {1,2,2,1 };
	// int B[] = {2,2};
	// int returnSize;
	// int * r = intersection(A, sizeof(A)/4, B, sizeof(B)/4, &returnSize);
	// for (size_t i = 0; i < returnSize; i++)
	// {
	// 	printf("%d\n", r[i]);
	// }

	// printf("%d\n", hasAlternatingBits(5));
	if(hasAlternatingBits(5))
		printf("true\n");
	else 
		printf("false\n");


	
}