/*
https://leetcode-cn.com/problems/number-of-segments-in-a-string/
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

int countSegments(char * s){
	int r = 0;
	while(*s)
	{
		if((*s != ' ') && (*(s+1) == ' '))
			r++;
		else if((*s != ' ') && (*(s+1) == '\0'))
			r++;

		s++;
	} 
	return r;
}

int main()
{
	// int A[] = {1,2,2,1 };
	// int B[] = {2,2};
	// int returnSize;
	// int * r = intersection(A, sizeof(A)/4, B, sizeof(B)/4, &returnSize);

	char *s = "";

	printf("%d\n", countSegments(s));


}