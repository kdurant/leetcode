#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

/*
给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
*/
bool containsDuplicate(int* nums, int numsSize) {
   for(size_t i = 0; i < numsSize; i++)
   {
        for(size_t j = i+1; j < numsSize; j++)
        {
            if(nums[i] == nums[j])
                return true;
        }
   }
   return false;
}

int main()
{
    // int nums[] = {0,11,0,3};
    int nums[] = {1,2,3,3};
    if(containsDuplicate(nums, sizeof(nums)/sizeof(int)))
    {
        printf("contain\n");
    }
    else
        printf("not\n");
    
    return 0;
} 