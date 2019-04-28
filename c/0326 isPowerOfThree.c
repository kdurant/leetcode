#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

bool isPowerOfThree(int n) {
    if(n <= 0)
		return false;

	if( n== 1)
		return true;
	
	while( (n%3) == 0 )
	{
		if(n == 3)
			return true;
		else
			n /= 3;
	}
	return false;
}

int main()
{
	if(isPowerOfThree(59049))
		printf("success\n");
	else
		printf("failed\n");
}