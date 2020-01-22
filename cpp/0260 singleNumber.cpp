/*
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

示例 :

输入: [1,2,1,3,2,5]
输出: [3,5]
注意：

结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

int* singleNumber(int* nums, int numsSize, int* returnSize)
{
    int  bitmask = 0;
    int* ret     = calloc(2, sizeof(int));

    *returnSize = 2;
    for(int i = 0; i < numsSize; i++)
        bitmask ^= nums[i];

    int diff = bitmask ^ (-bitmask);

    for(int i = 0; i < numsSize; i++)
    {
        if((nums[i] & diff) == diff)
            ret[0] ^= nums[i];
        else
            ret[1] ^= nums[i];
    }
    return ret;
}

int main(void)
{
    int  nums[] = {1, 1, 3, 4};
    int* ret    = malloc(sizeof(int) * 2);
    int  size;

    ret = singleNumber(nums, sizeof(nums) / sizeof(nums[0]), &size);

    for(int i = 0; i < size; i++)
        printf("%d\n", ret[i]);

    return 0;
}

*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        unordered_set<int> numbers;

        for(auto num : nums)
        {
            // 如果map中已经有这个元素了，则删除掉
            if(!numbers.insert(num).second)
                numbers.erase(num);
        }

        // map转vector
        vector<int> ret(numbers.begin(), numbers.end());
        return ret;
    }
};
int main(void)
{
    Solution    s;
    vector<int> nums = {1, 1, 2, 3};

    vector<int> ret = s.singleNumber(nums);
    for(size_t i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << "\t";
    }
    return 0;
}