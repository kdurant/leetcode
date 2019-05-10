/*
https://leetcode-cn.com/problems/maximum-product-of-three-numbers/

给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

示例 1:

输入: [1,2,3]
输出: 6
示例 2:

输入: [1,2,3,4]
输出: 24
注意:

给定的整型数组长度范围是[3,104]，数组中所有的元素范围是[-1000, 1000]。
输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。
*/

#include <stdio.h>
#include <stdlib.h>


int compare(void * data1, void * data2)
{
    return( *(int *)data1 - *(int*)data2);
}

int maximumProduct(int* nums, int numsSize){
    int r1, r2;
    qsort(nums, numsSize, sizeof(int), compare);

    r1 = nums[numsSize-1] * nums[numsSize-2] * nums[numsSize-3];;
    r2 =  nums[0] * nums[1] * nums[numsSize-1];

    return r1 > r2 ? r1 : r2;

}



int main()
{
    return 0;
}