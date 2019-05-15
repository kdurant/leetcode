/*
https://leetcode-cn.com/problems/monotonic-array/

如果数组是单调递增或单调递减的，那么它是单调的。

如果对于所有 i <= j，A[i] <= A[j]，那么数组 A 是单调递增的。 如果对于所有 i <= j，A[i]> = A[j]，那么数组 A 是单调递减的。

当给定的数组 A 是单调数组时返回 true，否则返回 false。
*/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>


bool isMonotonic(int* A, int ASize){
    int mode;
    if(A[0] >= A[ASize-1])
        mode = 1;
    else if(A[0] < A[ASize-1])
        mode = 0;

    for (size_t i = 0; i < ASize-1; i++)
    {
        if(mode)    // 递减
        {
            if(A[i] < A[i+1])
                return false;
        }
        else
        {
            if(A[i] > A[i+1])
                return false;
        }
        
    }
    return true;
}


int main()
{
    int A[] = {3,4,2,3};
    printf("%d\n", isMonotonic(A, sizeof(A)/4));
    return 0;
} 