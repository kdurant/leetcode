/*
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int i = 0;
    int j = numbersSize - 1;

    int* res = (int*)malloc(sizeof(int) * 2);
    while(i < j)
    {
        if(numbers[i] + numbers[j] > target)
            j--;
        else if(numbers[i] + numbers[j] < target)
            i++;
        else
            break;
    }
    res[0]      = i + 1;
    res[1]      = j + 1;
    *returnSize = 2;

    return res;
}

int main(void)
{
    int  a[] = {2, 7, 11, 15};
    int* res;
    int  len;
    res = twoSum(a, sizeof(a) / 4, 13, &len);

    for(int i = 0; i < len; i++)
    {
        printf("%d\t", res[i]);
    }

    return 0;
}
