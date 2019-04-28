#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
*/
int singleNumber(int* nums, int numsSize) 
{
    int ret=0, i = 0;  //ret的初值必须是0，因为任何东西异或0都得到本身，这才不会产生干扰
    for(i = 0; i < numsSize; i++)
    {
        ret ^= nums[i];
    }      
    return ret;
}

int main()
{
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    
    
    return 0;
}