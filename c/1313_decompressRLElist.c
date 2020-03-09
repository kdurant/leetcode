/*
给你一个以行程长度编码压缩的整数列表 nums 。

考虑每对相邻的两个元素 [a, b] = [nums[2*i], nums[2*i+1]] （其中 i >= 0 ），每一对都表示解压后有 a 个值为 b 的元素。

请你返回解压后的列表。

 

示例：

输入：nums = [1,2,3,4]
输出：[2,4,4,4]
解释：第一对 [1,2] 代表着 2 的出现频次为 1，所以生成数组 [2]。
第二对 [3,4] 代表着 4 的出现频次为 3，所以生成数组 [4,4,4]。
最后将它们串联到一起 [2] + [4,4,4,4] = [2,4,4,4]。
 

提示：

2 <= nums.length <= 100
nums.length % 2 == 0
1 <= nums[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decompress-run-length-encoded-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <stdio.h>
#include <stdlib.h>
int* decompressRLElist(int* nums, int numsSize, int* returnSize)
{
    *returnSize = 0;
    for(int i = 0; i < numsSize; i += 2)
        *returnSize += nums[i];

    int* res = malloc(*returnSize * sizeof(int));

    int offset = 0;
    for(int i = 0; i < numsSize; i += 2)
    {
        for(int j = 0; j < nums[i]; j++)
        {
            res[offset + j] = nums[i + 1];
        }
        offset += nums[i];
    }
    return res;
}

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5, 6};
    int returnSize;

    int* res = decompressRLElist(nums, sizeof(nums) / sizeof(nums[0]), &returnSize);

    for(int i = 0; i < returnSize; i++)
    {
        printf("%d\n", res[i]);
    }

    return 0;
}
