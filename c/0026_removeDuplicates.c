/*
https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/

给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>


int removeDuplicates(int* nums, int numsSize) {
    if(numsSize < 2)
        return numsSize;

    int s = 1;

    for(size_t i = 1; i < numsSize; i++)
    {
        // s用来保存不同元素的位置, 找到一个新的不同元素后, 将新元素放到s的位置,然后s++
        if (*(nums+i-1) != *(nums+i)) {
            *(nums+s) = *(nums+i);
            s++;
        }
    }
    return s;
}

int main()
{
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    // int nums[] = {0, 0, 0};
    // int nums[] = {1, 1, 2};
    int n = 0;
    n = removeDuplicates(nums, sizeof(nums)/sizeof(int));
    for(size_t i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }
    
    return 0;
}