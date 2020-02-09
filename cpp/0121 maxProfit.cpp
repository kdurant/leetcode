/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
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
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        if(len <= 1)
            return 0;
        vector<int> diff(len - 1);
        // 计算出相邻两天股票的差值，如果差值为正，则说明是赚钱的
        for(int i = 0; i < diff.size(); i++)
        {
            diff[i] = prices[i + 1] - prices[i];
        }

        vector<int> dp(diff.size());  // dp[i] 表示以 i 为结尾的最大连续子数组和
        dp[0]      = max(0, diff[0]);
        int profit = dp[0];

        for(int i = 1; i < diff.size(); i++)
        {
            dp[i]  = max(0, dp[i - 1] + diff[i]);
            profit = max(profit, dp[i]);
        }
        return profit;
    }
};

int main(void)
{
    Solution    s;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(prices) << endl;

    return 0;
}
