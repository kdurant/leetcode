动态规划把原问题分解为若干子问题，然后自底向上，先求解最小的子问题，把结果存储在表格种，在求解大的问题时，直接从表格中查询小的子问题的解，避免重复计算，从而提高算法效率

# 什么问题可以使用动态规划
1. 最优子结构
   最优子结构性质是指问题的最优解包含其子问题的最优解。`最优子结构是使用动态规划的最基本条件`，如果不具有此性质，就不可以使用动态规划解决

2. 子问题重叠
   子问题重叠是指在求解子问题的过程中，有大量的子问题是重复的，那么只需要求解一次，然后把结果存储在表格中，以后使用时可以直接查询，不需要再次求解。子问题重叠不是使用动态规划的`必要条件`，但问题存在子问题重叠更能充分彰显动态规划的优势。

# 使用动态规划步骤
1. 设定状态
2. 寻找状态转移方程
   > 为啥叫「状态转移方程」？为了听起来高端。你把 f(n)想做一个状态 n，这个状态 n是由状态n−1 和状态n−2 相加转移而来，这就叫状态转移，仅此而已。

   > 解动态规划的时候需要开一个数组，数组的每个元素f[i]或者f[i][j]代表什么


3. 利用状态转移方程式自底向上求解问题


# 斐波那契数列
```c
// 动态规划的入门示例
int fib(int n)
{
    if(n < 0)
        return -1;
    
    int *res = malloc(sizeof(int)* (n+1));
    res[0] = 1;
    res[1] = 1;
    for (size_t i = 2; i < n; i++)
    {
        res[i] = res[i-1] + res[i-2];
    }
    return res[n-1];    
}
```

# [70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)
## 分析
设函数F(N)表示走到第N级台阶走法的数量。
现在假设有10级台阶。现在就会出现两种情况：
1. 我们是从第9级，跨1级上来，到第10级
2. 我们是从第8级，跨2级上来，到第10级
其实对于任何第N级台阶，都会出现这两种情况，即第N级的前一步是走了1级或者两级。
所以如果我们统计F(10)的话，可以发现F(10) = F(9) + F(8)，即到第10级的走法等于到第9级的走法加上到第8级的走法。同理可得，F(9) = F(8) + F(7)，F(8) = F(7) + F(6)等等等等……

所以我们就得到了动态规划步骤1中的所说的所谓的`状态转移方程：`
> `dp(N) = dp(N-1) + dp(N-2)`,　dp[i]表示到第ｉ阶台阶的方案数

## 代码
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int climbStairs(int n)
{
    if(n < 0)
        return -1;

    int *dp = malloc(sizeof(int) * (n + 1));
    dp[0]   = 1;
    dp[1]   = 2;
    for(size_t i = 2; i < n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
}

int main()
{
    printf("%d\n", climbStairs(3));
}
```

# [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)
## 题目
给定一个整数数组 nums（[-2,1,-3,4,-1,2,1,-5,4]） ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

## 分析
dp[i] 表示nums中包含ｉ的前ｉ个元素的和。对于第ｉ个元素，有两种情况，如果前面i-1个元素的和为负数，只保留第ｉ个元素；否则，是当前数字与前面子序的和
状态转移方程$max(0, dp[i-1]) + a[i]$

| index | dp[] | Note                | nums |
| ----- | ---- | ------------------- | ---- |
| 0     | 0    | Placeholder         |
| 1     | -2   | max(0, dp[0])+ a[1] | -2   |
| 2     | 1    | max(0, dp[1])+ a[2] | 1    |
| 3     | -2   | max(0, dp[2])+ a[3] | -3   |
| 4     | 4    | max(0, dp[3])+ a[4] | 4    |
| 5     | 3    | max(0, dp[4])+ a[5] | -1   |
| 6     | 5    | max(0, dp[5])+ a[6] | 2    |
| 7     | 6    | max(0, dp[6])+ a[7] | 1    |
| 8     | 1    | max(0, dp[7])+ a[8] | -5   |
| 9     | 5    | max(0, dp[8])+ a[9] | 4    |

## 代码
```cpp
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        //dp[i]表示nums中以nums[i]结尾的最大子序和
        vector<int> dp(numsSize);
        dp[0] = nums[0];
        result = dp[0];
        for (int i = 1; i < numsSize; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(nums) << endl;

    return 0;
}
```

# [62. 不同路径](https://leetcode-cn.com/problems/unique-paths/)
我们令 dp[i][j] 是到达 i, j 最多路径，状态转移方程：dp[i][j] = dp[i-1][j] + dp[i][j-1]

坐标型动态规划

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // dp[m][n]表示到达(m,n)网格的路径方案
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(void)
{
    Solution s;
    cout << s.uniquePaths(7, 3) << endl;

    return 0;
}
```

# [55. 跳跃游戏](https://leetcode-cn.com/problems/jump-game/)
## 分析
假设可以到达数组最后一个位置n-1
- 从位置i到达，i < n-1
- 最后一步不超过跳跃的最大距离不能超过当前位置允许的最大距离: i + a[i] >= n-1

设：dp[i]表示能不能到达i位置
状态方程:
nums[i-1]+

| index | dp[] | Note                | nums |
| ----- | ---- | ------------------- | ---- |
| 0     | true | Placeholder         | 2    |
| 1     | -2   | max(0, dp[0])+ a[1] | 3    |
| 2     | 1    | max(0, dp[1])+ a[2] | 1    |
| 3     | -2   | max(0, dp[2])+ a[3] | 1    |
| 4     | 4    | max(0, dp[3])+ a[4] | 4    |


## 代码

# [674. 最长连续递增数列（LIS）](https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/)
给定一个未经排序的整数数组，找到最长且连续的的递增序列。返回连续递增数列的元素个数

## 分析
## 代码
```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int findLengthOfLCIS(int* nums, int numsSize)
{
    int res = 0;
    int max = 0;

    if(numsSize == 1)
        return 1;
    if(numsSize == 0 || nums == NULL)
        return 0;
    for(int i = 1; i < numsSize; i++)
    {
        if(nums[i] > nums[i - 1])
        {
            res++;
            if(res > max)
                max = res;
        }
        else
        {
            res = 0;
        }
    }
    return max + 1;
}

int main(void)
{
    int a1[] = {1, 3, 5, 4, 7};
    int a2[] = {2, 2, 2, 2, 2};
    int a3[] = {1, 3, 5, 7};
    printf("%d\n", findLengthOfLCIS(a1, sizeof(a1) / sizeof(int)));
    printf("%d\n", findLengthOfLCIS(a2, sizeof(a2) / sizeof(int)));
    printf("%d\n", findLengthOfLCIS(a3, sizeof(a3) / sizeof(int)));
    return 0;
}
```

# [198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/)
## 题目
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

## 分析
假如小偷站在第i家的屋顶，偷还是不偷？
1. 如果偷这家，那前面的i-1家就不能偷，能偷到的的最大值就是i-2家的最大值加上这一家的钱
2. 如果不偷，当前偷到的最大值就是偷完i-1家的最大值

状态转移方程为: F(i) = max(F(i-2) + i, F(i-1))

定义一个数组dp[], dp[i]表示小偷从第1号到第i+1号屋子偷钱的最大收益

| index | dp[] | Note                      | nums |
| ----- | ---- | ------------------------- | ---- |
| 0     | 2    | init                      | 2    |
| 1     | 7    | init                      | 7    |
| 2     | 11   | max(dp[0]+nums[2], dp[1]) | 9    |
| 3     | 11   | max(dp[1]+nums[3], dp[2]) | 3    |
| 4     | 12   | max(dp[2]+nums[4], dp[3]) | 1    |

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rob(int* nums, int numsSize){
    if(numsSize <= 0)
        return 0;
    
    if(numsSize == 1)
        return nums[0];
    
    int *dp = malloc(sizeof(int)*(numsSize));
    dp[0] = nums[0];
    dp[1] = nums[1] > nums[0] ? nums[1] : nums[0];

    for (size_t i = 2; i < numsSize; i++)
    {
        //状态转移方程为: F(i) = max(F(i-2) + i, F(i-1))
        dp[i] = dp[i-2]+nums[i] > dp[i-1] ? dp[i-2] + nums[i] : dp[i-1];
    }
    return dp[numsSize-1];
}

int main()
{
    int A[] = {1,2,3,1};
    printf("%d\n", rob(A, sizeof(A)/4));
}
```

# [1143. 最长公共子序列(LCS)](https://leetcode-cn.com/problems/longest-common-subsequence/)
给定两个字符串，求解这两个字符串的最长公共子序列（Longest Common Sequence）。比如字符串1：`BDCABA`；字符串2：`ABCBDAB`
则这两个字符串的最长公共子序列长度为4，最长公共子序列是：`BCBA`

# [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

## 分析
- 买卖股票的最佳时机抽象一下就是找到一个子序列尾和首的差最大(原数组两个元素的最大差等于求差数组的最大子序和！)
- 要在第i天卖出获利最大，则要求第i-1天买入的价格最小
dp[i] 表示以`i`为结尾的最大连续子数组和  
最大利润=max{前一天最大利润, 今天的价格 - 之前最低价格}

```cpp
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
        if (len <= 1)
            return 0;
        vector<int> diff(len - 1);
        // 计算出相邻两天股票的差值，如果差值为正，则说明是赚钱的
        for (int i = 0; i < diff.size(); i++) {
            diff[i] = prices[i + 1] - prices[i];
        }

        vector<int> dp(diff.size()); // dp[i] 表示以 i 为结尾的最大连续子数组和
        dp[0] = max(0, diff[0]);
        int profit = dp[0];

        for (int i = 1; i < diff.size(); i++) {
            dp[i] = max(0, dp[i - 1] + diff[i]);
            profit = max(profit, dp[i]);
        }
        return profit;
    }
};

int main(void)
{
    Solution s;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(prices) << endl;

    return 0;
}
```

# 01背包问题(Knapsack Problem)
有N个物品和一个最大容量为V的背包，第i件物品的空间`c[i]`，价值是`w[i]`。问那些物品装进背包可使价值总和最大？`每种物品最多选一次`

## 状态转移方程
$$F[i,v] = max\{F[i-1, v], F[i-1, v-c_i]+ w_i\} $$

> F[i, v] 表示前 i 件物品恰放入一个剩余容量为 v 的背包可以获得的最大价值

到了第i件时，有两个选择：
- 放
    * 问题就转化为“前 i − 1 件物品放入剩下的容量为 v − Ci 的背包中”，此时能获得的最大价值就是 F [i − 1; v − Ci] 再加上通过放入第 i 件物品获得的价值 Wi。
- 不放
    * 问题转化为“前 i − 1 件物品放入容量为 v 的背包中”，价值为 F [i − 1, v]

## 例题
有4个物品，背包总容量为8，背包最多能装入价值为多少的物品
|      |     |     |     |     |
| ---- | --- | --- | --- | --- |
| 编号 | 1   | 2   | 3   | 4   |
| 体积 | 2   | 3   | 4   | 5   |
| 价值 | 3   | 4   | 5   | 6   |

# 凑零钱
有三种硬币，分别面值２元，５元，７元，每枚硬币足够多。买一本书需要２７元，如何用最少的硬币组合付清

# [凑零钱](https://leetcode-cn.com/problems/coin-change/)
coins = [1, 2, 5], amount = 11



```cpp
vector<int> dp(amount + 1, amount + 1);
```
`f[x] = min{f[x-1] + 1, f[x-2] + 1, f[x-5] + 1};`

| index | dp[] | 备注                                                        |
| ----- | ---- | ----------------------------------------------------------- |
| 0     | 0    |
| 1     | 1    | min(dp[0] + 1, df[-1] + 1, dp[-4] + 1),df[-1], dp[-4]无意义 |
| 2     | 1    | min(dp[1] + 1, df[0] + 1, dp[-３] + 1), df[-3] 无意义       |
| 3     | ２   | min(dp[２] + 1, df[１] + 1, dp[-２] + 1), df[-2] 无意义     |
| 4     | ２   | min(dp[３] + 1, df[２] + 1, dp[-1] + 1), df[-1] 无意义      |
| 5     | 1    | min(dp[４] + 1, df[３] + 1, dp[0] + 1)                      |
| 6     | ２   | min(dp[５] + 1, df[４] + 1, dp[1] + 1)                      |
| 7     | 2    | min(dp[６] + 1, df[５] + 1, dp[2] + 1)                      |
| 8     | 3    | min(dp[7] + 1, df[6] + 1, dp[3] + 1)                        |
| 9     | 3    | min(dp[8] + 1, df[7] + 1, dp[4] + 1)                        |
| 10    | 2    | min(dp[9] + 1, df[8] + 1, dp[5] + 1)                        |
| 11    | 3    | min(dp[10] + 1, df[9] + 1, dp[6] + 1)                       |

```cpp
#include <algorithm>
#include <iostream>
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
```