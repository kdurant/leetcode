/*
https://leetcode-cn.com/problems/number-of-segments-in-a-string/

统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
请注意，你可以假定字符串里不包括任何不可打印的字符。

示例:

输入: "Hello, my name is John"
输出: 5
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