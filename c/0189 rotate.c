#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

/*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
*/
void rotate(int* nums, int numsSize, int k) {
    int temp = 0;
    for(size_t i = 0; i < k; i++)
    {
        temp = nums[numsSize-1];
        for(size_t j = numsSize-1; j > 0; j--)
        {
            nums[j] = nums[j-1];
        }
        nums[0] = temp;        
    }
}

int main()
{
    int nums[] = {1,2,3,4,5,6,7};
    rotate(nums, 7, 8);
    for(size_t i = 0; i < 7; i++)
    {
        printf("%d ", nums[i]);
    }
    
    return 0;
}