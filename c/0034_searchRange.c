/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

int binary_search(int* nums, int len, int target)
{
    int left  = 0;
    int right = len - 1;
    int mid   = 0;

    while(left <= right)
    {
        mid = (left + right) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            right = mid - 1;  // left，本次比较之前的一个元素
        else if(nums[mid] < target)
            left = mid + 1;
    }

    return -1;
}

int left_binary_search(int* nums, int len, int target)
{
    int left  = 0;
    int right = len;
    int mid   = 0;

    while(left < right)
    {
        mid = (left + right) / 2;
        if(nums[mid] == target)
            right = mid;
        else if(nums[mid] > target)
            right = mid;
        else if(nums[mid] < target)
            left = mid + 1;
    }

    if(left == len)
        return -1;

    return nums[left] == target ? left : -1;
}

int right_binary_search(int* nums, int len, int target)
{
    int left  = 0;
    int right = len;
    int mid   = 0;

    while(left < right)
    {
        mid = (left + right) / 2;
        if(nums[mid] == target)
            left = mid + 1;
        else if(nums[mid] > target)
            right = mid;
        else if(nums[mid] < target)
            left = mid + 1;
    }

    if(left == 0)
        return -1;

    return nums[left - 1] == target ? left - 1 : -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int* ret    = malloc(sizeof(int) * 2);
    *returnSize = 2;

    ret[0] = left_binary_search(nums, numsSize, target);
    ret[1] = right_binary_search(nums, numsSize, target);
    return ret;
}

int main(int argc, char* argv[])
{
    int  nums1[] = {1, 2, 2, 2, 3};
    int  returnSize;
    int* ret = malloc(sizeof(int) * 2);
    ret      = searchRange(nums1, sizeof(nums1) / sizeof(nums1[0]), 2, &returnSize);
    printf("%d\n", ret[0]);
    printf("%d\n", ret[1]);

    return 0;
}
