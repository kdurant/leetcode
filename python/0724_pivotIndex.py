""" 
给定一个整数类型的数组 nums，请编写一个能够返回数组 “中心索引” 的方法。

我们是这样定义数组 中心索引 的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。

如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。

 

示例 1：

输入：
nums = [1, 7, 3, 6, 5, 6]
输出：3
解释：
索引 3 (nums[3] = 6) 的左侧数之和 (1 + 7 + 3 = 11)，与右侧数之和 (5 + 6 = 11) 相等。
同时, 3 也是第一个符合要求的中心索引。
示例 2：

输入：
nums = [1, 2, 3]
输出：-1
解释：
数组中不存在满足此条件的中心索引。
 

说明：

nums 的长度范围为 [0, 10000]。
任何一个 nums[i] 将会是一个范围在 [-1000, 1000]的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-pivot-index
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
from typing import List


class Solution:
    # 中心索引之前的所有数组元素之和+中心索引之后的元素之和+索引元素==数组元素总和
    # 先求出总和，然后根据题意，数组中心两边相等，得到2*SUM==sum-nums[i]的判断条件
    def pivotIndex(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return -1
        sum_all = sum(nums)
        sum1 = 0
        for i in range(len(nums)):
            sum1 += nums[i]
            if sum1 - nums[i] == sum_all - sum1:
                return i
        return -1

    def pivotIndex1(self, nums: List[int]) -> int:
        for index, i in enumerate(nums):
            if sum(nums[index + 1:]) == sum(nums[:index]):
                return index
        return -1


s = Solution()
print(s.pivotIndex([1, 7, 3, 6, 5, 6]))
print(s.pivotIndex([-1, -1, -1, -1, -1]))
