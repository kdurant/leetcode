/*
https://leetcode-cn.com/problems/squares-of-a-sorted-array/

给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

示例 1：
输入：[-4,-1,0,3,10]
输出：[0,1,9,16,100]

示例 2：
输入：[-7,-3,2,3,11]
输出：[4,9,9,49,121]
 
提示：
1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A 已按非递减顺序排序。
在真实的面试中遇到过这道题？
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 从前向后遍历数组中的非负数部分，并且反向遍历数组中的负数部分。
 * [-3, -2, -1, 4, 5, 6]
 */
int* sortedSquares(int* A, int ASize, int* returnSize){
    int i = 0;
    int j = ASize-1;
    int k = ASize-1;
    int *result = malloc(ASize*sizeof(int));
    *returnSize = ASize;

    while(i <= j)
    {
        if(abs(A[i]) <= abs(A[j]))
        {
            result[k--] = A[j]*A[j];
            j--;
        }
        else
        {
            result[k--] = A[i]*A[i];
            i++;
        }
        
    }
    
    return result; 
}

int main()
{
    int r;
    int A[] = {-4,-1,0,3,10};
    int *data;
    data = sortedSquares(A, sizeof(A)/4, &r);

    for (size_t i = 0; i < r; i++)
    {
        printf("%d\t", data[i]);
    }
    
    
    return 0;
} 