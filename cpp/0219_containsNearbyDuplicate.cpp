/*
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。

 

示例 1:

输入: nums = [1,2,3,1], k = 3
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1
输出: true
示例 3:

输入: nums = [1,2,3,1,2,3], k = 2
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contains-duplicate-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        //          nums[i], i
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++)
        {
            if(map.count(nums[i]))
            {
                // 当前位置和之前保存的位置比较
                if(i - map[nums[i]] + 1 <= k)
                    return true;
                else
                    map[nums[i + 1]] = i + 1;
            }
            else
                map[nums[i]] = i + 1;
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    Solution    s;
    vector<int> nums{1, 2, 3, 1};
    cout << s.containsNearbyDuplicate(nums, 3) << endl;
    return 0;
}