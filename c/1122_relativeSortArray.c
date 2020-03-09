/*
给你两个数组，arr1 和 arr2，

arr2 中的元素各不相同
arr2 中的每个元素都出现在 arr1 中
对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。

 

示例：

输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
输出：[2,2,2,1,4,3,3,9,6,7,19]
 

提示：

arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
arr2 中的元素 arr2[i] 各不相同
arr2 中的每个元素 arr2[i] 都出现在 arr1 中

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/relative-sort-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
    int* ret    = calloc(1001, sizeof(int));
    int  idx    = 0;
    *returnSize = arr1Size;

    for(int i = 0; i < arr1Size; i++)
        ret[arr1[i]]++;

    for(int i = 0; i < arr2Size; i++)
        ret[arr2[i]] *= -1;

    int cur = 0;

    // ret中已经保存了 arr1 和 arr2 的所有信息
    for(int i = 0; i < arr2Size; i++)  // 先挑arr2中有的数
    {
        while(ret[arr2[i]] < 0)
        {
            arr1[cur++] = arr2[i];
            ret[arr2[i]]++;
            idx++;
        }
    }

    for(int i = 0; i < 1001; i++)
    {
        while(ret[i] > 0)
        {
            arr1[cur++] = i;
            ret[i]--;
        }
    }
    return arr1;
}

int main(void)
{
    int arr1[] = {28, 6, 22, 8, 44, 17};
    int arr2[] = {22, 28, 8, 6};
    int returnSize;

    relativeSortArray(arr1, sizeof(arr1) / sizeof(arr1[0]), arr2, sizeof(arr2) / sizeof(arr2[0]), &returnSize);

    for(int i = 0; i < returnSize; i++)
    {
        printf("%d\n", arr1[i]);
    }
    return 0;
}
