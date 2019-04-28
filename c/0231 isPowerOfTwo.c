#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

bool isPowerOfTwo(int n) {
	int r = 0;
	if(n < 0)
		return false;
	for(size_t i = 0; i < 32; i++)
	{
		r += (n>>i) & 0x01;
	}
	if (r == 1)
		return true;
	else
	{
		return false;
	}	
}

int main()
{
	if(isPowerOfTwo(-2147483648))
		printf("success\n");
	else
		printf("failed\n");
}