#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
*/
void moveZeroes(int* nums, int numsSize) {
    int cnt = 0;
    for(size_t i = 0; i < numsSize-cnt; )
    {
        if(nums[i] == 0 )
        {
            cnt = cnt + 1;
            for(size_t j = i; j < numsSize-1; j++)
            {
                nums[j] = nums[j+1];
            }
            
            if(i != numsSize -1)
                nums[numsSize-1] = 0;
        }
        else
            i++;
    }
}

int main()
{
    // int nums[] = {0,11,0,3};
    int nums[] = {0,0};
    // int nums[] = {1,0};
    // int nums[] = {1,0,1};
    moveZeroes(nums, sizeof(nums)/sizeof(int));
    for(size_t i = 0; i < sizeof(nums)/sizeof(int); i++)
    {
        printf("%d ", *(nums+i));
    }
    
    return 0;
} 