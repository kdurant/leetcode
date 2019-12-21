/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    /**
     * @brief
     *
     * @param nums
     * @param target
     * @return vector<int>
     */
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int, int> hash;

        for(int i = 0; i < nums.size(); i++)
        {
            if(hash.count(nums[i]))
                return {hash[nums[i]], i};
            hash[target - nums[i]] = i;  //记录：哈希表[target - 当前数字] = 当前数字的索引
            /**
             * 1. hash key = 7, value = 0
             *  当数组元素是7的时候，查询到hash表中有键为7的item时，说明数组前面有2的元素
             * 2. hash key = -2, value = 1
             * 3. hash key = 2, value = 2
             */
        }

        return {-1, -1};
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {2, 11, 7, 15};
    Solution    s;

    vector<int> r;
    r = s.twoSum(nums, 9);

    for(int i = 0; i < r.size(); i++)
    {
        cout << r[i] << "\t";
    }
    cout << endl;

    return 0;
}
