贪心算法，又名贪婪法，是寻找最优解问题的常用方法，这种方法模式一般将求解过程分成若干个步骤，但每个步骤都应用贪心原则，选取当前状态下最好/最优的选择（局部最有利的选择），并以此希望最后堆叠出的结果也是最好/最优的解。

> 某个问题的最优解包含着其子问题的最优解。这种性质称为最优子结构性质

贪婪法的基本步骤：

1. 从某个初始解出发；
2. 采用迭代的过程，当可以向目标前进一步时，就根据局部最优策略，得到一部分解，缩小问题规模；
3. 将所有解综合起来。

优点：简单，高效，省去了为了找最优解可能需要穷举操作，通常作为其它算法的辅助算法来使用；

缺点：不从总体上考虑其它可能情况，每次选取局部最优解，不再进行回溯处理，所以很少情况下得到最优解。

# 找零钱问题

# [122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/best-time-to-buy-and-sell-stock-ii-zhuan-hua-fa-ji/)
思路是遍历整个股票交易日价格列表price，将所有上涨交易日的利润都赚到，所有下降交易日都不买卖；

1. 设 tmp 为第 i-1 天买和 i 天卖可以赚取的利润，即 prices[i] - prices[i - 1] ；
2. 当该天利润为正 tmp > 0 ，则将利润加入总利润 profit ；
3. 遍历完成后返回总利润 profit 。
```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize)
{
    int r   = 0;
    int tmp = 0;
    if((pricesSize == 1) || (pricesSize == 0))
        return 0;
    for(int i = 1; i < pricesSize; i++)
    {
        tmp = prices[i] - prices[i - 1];
        if(tmp > 0)
            r += tmp;
    }
    return r;
}

int main(void)
{
    int a[] = {7, 1, 5, 3, 6, 4};
    printf("%d\n", maxProfit(a, sizeof(a) / 4));

    int b[] = {1, 2};
    printf("%d\n", maxProfit(b, sizeof(b) / 4));

    return 0;
}
```
# [392. 判断子序列](https://leetcode-cn.com/problems/is-subsequence/)
## 题目
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

## 分析


# [455. 分发饼干](https://leetcode-cn.com/problems/assign-cookies/solution/you-xian-man-zu-wei-kou-xiao-de-xiao-peng-you-de-x/)
## 题目
假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。对每个孩子 i ，都有一个胃口值 gi ，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j ，都有一个尺寸 sj 。如果 sj >= gi ，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

注意：

你可以假设胃口值为正。
一个小朋友最多只能拥有一块饼干。

## 分析

## 代码
```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int compare(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if(arg1 < arg2)
        return -1;
    if(arg1 > arg2)
        return 1;
    return 0;
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    int r = 0;
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);

    int i = 0;
    int j = 0;

    while(i < gSize & j < sSize)
    {
        if(g[i] <= s[j])
        {
            r++;
            i++, j++;
        }
        else
        {
            j++;
        }
    }
    return r;
}

int main(void)
{
    int g[] = {10, 9, 8, 7};  // 每个孩子的食量
    int s[] = {5, 6, 7, 8};   // 饼干的尺寸

    printf("%d\n", findContentChildren(g, sizeof(g) / 4, s, sizeof(s) / 4));
    return 0;
}
```

# [860. 柠檬水找零](https://leetcode-cn.com/problems/lemonade-change/solution/lemonade-change-tan-xin-suan-fa-by-jyd/)
## 题目
在柠檬水摊上，每一杯柠檬水的售价为 5 美元。

顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。

每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。

注意，一开始你手头没有任何零钱。

如果你能给每位顾客正确找零，返回 true ，否则返回 false 。
## 分析
- 题意每张账单只能是5、10、20
- 柠檬水均是5元一份
- 店家自己没有零钱
* 解法与思路
  - 当收到20时
    * 优先匹配店家手里的一张10和一张5，如有返回true
        - 店家手里的10--
        - 店家手里的5--
    * 如没有重新匹配3张15，如有返回true
        - 店家手里的5-=3
    * 如都没有返回false
  - 当收到10时
    * 优先匹配一张5如有返回true
        - 店家手里的5--，10++
    * 如没有返回false
  - 当收到5时
    * 店家手里的5++

## 代码
```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
bool lemonadeChange(int* bills, int billsSize)
{
    int five = 0;
    int ten  = 0;
    for(int i = 0; i < billsSize; i++)
    {
        if(bills[i] == 5)
            five++;
        else if(bills[i] == 10)
        {
            if(five == 0)
                return false;
            five--;
            ten++;
        }
        else
        {
            if(five > 0 && ten > 0)
            {
                five--;
                ten--;
            }
            else if(five >= 3)
                five -= 3;
            else
                return false;
        }
    }
    return true;
}
int main(void)
{
    int bills[] = {5, 5, 5, 10, 20};
    printf("%d\n", lemonadeChange(bills, sizeof(bills) / 4));
    return 0;
}
```

# [1029. 两地调度](https://leetcode-cn.com/problems/two-city-scheduling/solution/er-cha-shu-de-chui-xu-bian-li-by-leetcode/)

# 0-1背包问题
我们有 n 种物品，物品 j 的重量为wj，价格为pj。
我们假定所有物品的重量和价格都是非负的。背包所能承受的最大重量为W。
如果限定每种物品只能选择0个或1个，则问题称为0-1背包问题