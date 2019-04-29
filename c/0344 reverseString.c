/*
https://leetcode-cn.com/problems/reverse-string/

编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

void reverseString(char* s, int sSize) {
    char *n = (char *)malloc(sizeof(char)*sSize);
    for(size_t i = sSize; i > 0; i--)
    {
        n[sSize-i] = s[i-1];
    }
  
    memcpy(s, n , sSize);
    free(n);
}

int main()
{
    // int nums[] = {0,11,0,3};
    char nums1[] = {'a', 'b', 'c', 'd'};
    reverseString(nums1, 4);
    for(size_t i = 0; i < 4; i++)
    {
        printf("%c ", nums1[i]);
    }
    return 0;
} 