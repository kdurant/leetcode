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

/**
 * @brief 
 * 使用额外的内存空间保存数据, 空间复杂度O(n)
 * @param s 
 * @param sSize 
 */
void reverseString1(char* s, int sSize) {
    char *n = (char *)malloc(sizeof(char)*sSize);
    for(size_t i = sSize; i > 0; i--)
    {
        n[sSize-i] = s[i-1];
    }
  
    memcpy(s, n , sSize);
    free(n);
}

/**
 * @brief 
 * 双指针，原地翻转
 * @param s 
 * @param sSize 
 */
void reverseString2(char* s, int sSize) {
    int i = 0;
    int j = sSize-1;
    int tmp;
    while(i < j)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}

void swap(int start, int end, char *s)
{
    if(start >= end)
        return;
    
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    swap(start+1, end-1, s);
}
/**
 * @brief 递归的交换首尾字符
 * 
 * @param s 
 * @param sSize 
 */
void reverseString3(char *s, int sSize)
{
    int len = sSize-1;
    swap(0, len, s);
}

int main()
{
    // int nums[] = {0,11,0,3};
    char nums1[] = {'a', 'b', 'c', 'd'};
    reverseString3(nums1, sizeof(nums1)/sizeof(char));
    for(size_t i = 0; i < sizeof(nums1)/sizeof(char); i++)
    {
        printf("%c ", nums1[i]);
    }
    return 0;
} 