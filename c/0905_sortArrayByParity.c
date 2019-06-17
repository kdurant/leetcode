/*
https://leetcode-cn.com/problems/sort-array-by-parity/

给定一个非负整数数组 A，返回一个由 A 的所有偶数元素组成的数组，后面跟 A 的所有奇数元素。

你可以返回满足此条件的任何数组作为答案。
示例：

输入：[3,1,2,4]
输出：[2,4,3,1]
输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
 
提示：
1 <= A.length <= 5000
0 <= A[i] <= 5000
*/

#include <stdio.h>

int* sortArrayByParity(int* A, int ASize, int* returnSize){
    int i = 0;
    int j = ASize - 1;
    int tmp;
    while(i < j)
    {
        if( ( (A[i] % 2) == 1)  )       // 
        {
            if ( (A[j] % 2) == 0)   // A[i]奇数， A[j]偶数的时候交换
            {
                tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
                i++;
                j--;
            }
            else
                j--;
        }
        else
            i++;
    }
    *returnSize = ASize;
    return A;
}

int main()
{
    int r;
    int A[] = {4279,4333,4035,914,3650,590,1267,1101,4412};
    int *data;
    data = sortArrayByParity(A, sizeof(A)/4, &r);

    for (size_t i = 0; i < r; i++)
    {
        printf("%d\t", data[i]);
    }
    
    
    return 0;
} 