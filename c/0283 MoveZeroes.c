/*
https://leetcode-cn.com/problems/move-zeroes/

给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>


void moveZeroes(int* nums, int numsSize) {
    int cnt = 0;
    // 如果当前索引的值是0，则将后面的数据往前移动，在最后面补0
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

/*
双指针
i遍历数组，j用作不为0的数的索引
如果当前变力的数不是0，将现在的数放到索引j的位置

没有遇到0之前，nums[i]和nums[j]的交换没有意义
遇到0之后，i继续向后移动，j保持不变
遇到下一个不为0的数后，交换这两个数

*/
void moveZeroes1(int* nums, int numsSize) {
    int j = 0;
    int temp;
    for (size_t i = 0; i < numsSize; i++)
    {
        if(nums[i] != 0)    // 
        {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
    }
}

int main()
{
    int nums[] = {0,11,3};
    // int nums[] = {0,0};
    // int nums[] = {1,0};
    // int nums[] = {1,0,1};
    moveZeroes(nums, sizeof(nums)/sizeof(int));
    for(size_t i = 0; i < sizeof(nums)/sizeof(int); i++)
    {
        printf("%d ", *(nums+i));
    }
    
    return 0;
} 