/*
https://leetcode-cn.com/problems/sort-array-by-parity-ii/

给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。

对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。

你可以返回任何满足上述条件的数组作为答案。

 

示例：

输入：[4,2,5,7]
输出：[4,5,2,7]
解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
 

提示：

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000
 
*/

#include <stdio.h>
#include <malloc.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize){
    int odd = 1;
    int even = 0;
    int *res = malloc(sizeof(int)*(ASize));
    *returnSize = ASize;
    for (size_t i = 0; i < ASize; i++)
    {
        if(A[i] % 2 == 0)
        {
            res[even] = A[i];
            even += 2;
        }
        else
        {
            res[odd] = A[i];
            odd += 2;
        }
    }
    return res;
}

int main()
{
    int A[] = {679,179,130,932,749,108};
    int returnSize;

    int *res = malloc(sizeof(int)* (sizeof(A)/4));
    res = sortArrayByParityII(A, sizeof(A)/4, &returnSize);
    for (size_t i = 0; i < returnSize; i++)
    {
        printf("%d\n", res[i]);
    }
    
}