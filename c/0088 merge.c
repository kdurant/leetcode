/*
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    // nums1中的元素 后移 n
    // 1,2,3,0,0,0

    for(int i = m - 1; i >= 0; i--)
    {
        nums1[n + i] = nums1[i];
    }

    //
    int i = 0;
    int j = 0;
    int k = 0;
    while((i < m) && (j < n))
    {
        if(nums1[n + i] < nums2[j])
        {
            nums1[k++] = nums1[n + i];
            i++;
        }
        else
        {
            nums1[k++] = nums2[j];
            j++;
        }
    }

    while(j < n)
    {
        nums1[k++] = nums2[j++];
    }
}

int main(void)
{
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {2, 5, 6};

    merge(nums1, sizeof(nums1) / 4, 3, nums2, sizeof(nums2) / 4, 3);
    for(int i = 0; i < 6; i++)
    {
        printf("%d\t", nums1[i]);
    }

    return 0;
}
