#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

int missingNumber(int* nums, int numsSize){
	int r = numsSize;
	for (size_t i = 0; i < numsSize; i++)
	{
		r ^= *(nums + i); 
		r ^= i;
	}
	return r;
}






int main()
{
	int A[] = {9,6,4,2,3,5,7,0,1};

	printf("%d\n", missingNumber(A, sizeof(A)/4));
}