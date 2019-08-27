/*
给定两个没有重复元素的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。

nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出-1。

示例 1:

输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
    对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
    对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。
示例 2:

输入: nums1 = [2,4], nums2 = [1,2,3,4].
输出: [3,-1]
解释:
    对于num1中的数字2，第二个数组中的下一个较大数字是3。
    对于num1中的数字4，第二个数组中没有下一个更大的数字，因此输出 -1。
注意:

nums1和nums2中所有元素是唯一的。
nums1和nums2 的数组大小都不超过1000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-element-i
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int* r        = malloc(nums1Size * sizeof(int));
    int  idx      = 0;
    bool big_flag = false;
    *returnSize   = nums1Size;
    for(int i = 0; i < nums1Size; i++)
    {
        big_flag = false;
        for(int j = 0; j < nums2Size; j++)
        {
            if(nums2[j] == nums1[i])  // 在nums2中先找到nums1中的值
            {
                for(int k = j; k < nums2Size; k++)
                {
                    if(nums2[k] > nums1[i])
                    {
                        *(r + idx) = nums2[k];
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
                break;
            }
        }
    }
    return r;
}

int main(void)
{
    int  nums1[] = {2, 4};
    int  nums2[] = {1, 2, 3, 4};
    int  len;
    int* r = nextGreaterElement(nums1, sizeof(nums1) / 4, nums2, sizeof(nums2) / 4, &len);

    for(int i = 0; i < len; i++)
    {
        printf("%d\t", r[i]);
    }

    return 0;
}
