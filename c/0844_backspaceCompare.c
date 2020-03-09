/*
https://leetcode-cn.com/problems/backspace-string-compare/

给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

示例 1：

输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool backspaceCompare(char * S, char * T){
	char S1[200];
	char T1[200];
	int s1_len = 0;
	int t1_len = 0;
	memset(S1, 0, 200);
	memset(T1, 0, 200);
	while(*S)
	{
		if(*S == '#')
		{
			if(s1_len > 0)
				s1_len = s1_len-1;
		}
		else
		{
			S1[s1_len] = *S;
			s1_len++;
		}
		S++;
	}

	while(*T)
	{
		if(*T == '#')
		{
			if(t1_len > 0)
				t1_len = t1_len-1;
		}
		else
		{
			T1[t1_len] = *T;
			t1_len++;
		}
		T++;
	}

	if(t1_len != s1_len)
		return false;
	else
	{
		for (size_t i = 0; i < s1_len; i++)
		{
			if(S1[i] != T1[i])
				return false;
		}
		
	}
	
	return true;	
}

int main()
{
	int A[] = {4,3,2,1};
	char *s = "ab#c";
	char *t = "ad#c";
	backspaceCompare(s, t);
	// printf("%d\n", removeElement(A, sizeof(A)/4, 2));
	return 0 ;
}