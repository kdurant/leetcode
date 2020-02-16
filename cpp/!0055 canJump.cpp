#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int          len = nums.size();
        vector<bool> dp(len, false);

        dp[0] = true;
        int i, j;
        for(i = 1; i < len; i++)
        {
            for(j = 0; j < nums[i - 1]; j++)
            {
                if(i + j > len - 1)
                    break;
                dp[i + j] = true;
            }
            if(dp[i] == false)
                return false;
        }

        return dp[len - 1];
    }
};

int main(void)
{
    Solution s;
    //  vector<int> nums{2, 3, 1, 1, 4};
    //  vector<int> nums{3, 2, 1, 0, 4};
    //  vector<int> nums{0, 2, 3};  // false
    vector<int> nums{1, 2};
    cout << s.canJump(nums) << endl;

    return 0;
}
