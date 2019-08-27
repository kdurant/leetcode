/*
给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。

示例 1:

输入: [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数； 
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
注意: 输入数组的长度不会超过 10000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-element-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int* nextGreaterElements(int* nums, int numsSize, int* returnSize)
{
    int* r        = malloc(numsSize * sizeof(int));
    int  idx      = 0;
    bool big_flag = false;
    int  pos      = 0;
    int  target;

    *returnSize = numsSize;

    for(int i = 0; i < numsSize; i++)
    {
        target   = nums[i];
        big_flag = false;
        for(int j = i; j < numsSize + i; j++)
        {
            if(nums[j % numsSize] > target)
            {
                *(r + idx) = nums[j % numsSize];
                big_flag   = true;
                idx++;
                break;
            }
        }
        if(big_flag == false)
        {
            *(r + idx) = -1;
            idx++;
        }
    }
    return r;
}

int main(void)
{
    int  nums[] = {1, 2, 1};
    int  len;
    int* r = nextGreaterElements(nums, sizeof(nums) / 4, &len);
    for(int i = 0; i < len; i++)
    {
        printf("%d\t", r[i]);
    }

    return 0;
}
