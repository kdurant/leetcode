/*
https://leetcode-cn.com/problems/binary-prefix-divisible-by-5
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