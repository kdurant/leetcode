/*
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3
解释: 11 = 5 + 5 + 1
示例 2:

输入: coins = [2], amount = 3
输出: -1
说明:
你可以认为每种硬币的数量是无限的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-change
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // dp数组的大小由金额决定, 表示金额为ｉ的零钱，需要多少枚硬币
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++)
        {
            /*
             * f[x] = min{f[x-1] + 1, f[x-2] + 1, f[x-5] + 1};
             * 依次算出f[x-1], f[x-2], f[x-5],和默认值比较，算出最小值
             */
            for(int coin : coins)
            {
                if(coin <= i)  //只有当可选钱币数额小于需要凑的零钱总数才有意义
                    dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main(void)
{
    Solution    s;
    vector<int> coins{1, 2, 5};
    cout << s.coinChange(coins, 11) << endl;

    return 0;
}
