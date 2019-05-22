对于递归的程序，有两个要求：

1. 一个问题的解可以分解为几个子问题的解
2. 这个问题与分解之后的子问题，除了数据规模不同，求解思路完全一样
3. 存在递归终止条件，即必须有一个明确的递归结束条件，称之为递归出口


# 等差数列求和
```c
int sum(int n)
{
    int result = 0;
    if(n == 1)
        return 1;
    else
    {
        result = n + sum(n-1);
        return result;
    }
}
```
1. 子问题是`1+2+...N-1`, 和原问题一致且更简单
2. 
3. `n=1`时，跳出递归

# 阶乘
1. 子问题是`N-1 * N-2 * ... * 2 * 1`, 和原问题一致且更简单
2. 
3. `n=0`时，跳出递归

```c
int factorial(int n)
{
    int result = 1;
    int tmp;
    if(n == 0)
        return 1;
    else
    {
        tmp = factorial(n-1);
        result = n * tmp;
    }
    
    return result;
}
```

# 折半查找递归算法

# 两个正整数的最大公约数

# 斐波那契数列
在数学上，斐波纳契数列以如下被以递推的方法定义：F(1)=1，F(2)=1, F(n)=F(n-1)+F(n-2)（n>=3，n∈N*）,`1、1、2、3、5、8、13、21、34、……`
```c
int fibonacci(int n)
{
    int result = 0;
    if( (n == 1) || (n == 2) )
        return 1;
    else
    {
        result = fibonacci(n-1) + fibonacci(n-2);
        return result;
    }
}
```

# [爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)
设跳n个台阶有f(n)种方法，
爬1个：1种
爬2个：2种
爬n个：面临两种选择：
（1） 第一次爬1个，此时剩余n-1个台阶，有f(n-1)种方法
（2） 第一次爬2个，此时剩余n-2个台阶，有f(n-2)种方法

所以n个台阶的走法就等于现在1阶后，n-1个台阶的走法，然后加上先走2阶后，n-2个台阶的走法

> 加法原理

```c
int climbStairs(int n)
{
    int result = 0;
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    
    result = climbStairs(n-1) + climbStairs(n-2);
    return result;
}
```
效率太低

```c
int climbStairs(int n) 
{
    if(n == 1)
        return 1;
    int a = 1;
    int b = 2;
    int i = 2;
    for(int i=2;i<n;i++)
    {
        int x = a + b;
        a = b;
        b = x;
    }
    return b; 
}
```


# 汉诺塔问题

# 小猴子吃桃
小猴子第一天摘下若干桃子,当即吃掉一半,又多吃一个.第二天早上又将剩下的桃子吃
一半,又多吃一个.以后每天早上吃前一天剩下的一半另一个.到第10天早上猴子想再吃时发
现,只剩下一个桃子了.问第一天猴子共摘多少个桃子？

```c
// 每天吃一半且多一个
// 今天的数量 = （明天的数量+1）*2
int monkeyEatPeach(int n)
{
    int result = 0;
    int tmp;
    if(n == 1) 
        return 1;
    else
    {
        tmp = (monkeyEatPeach(n-1) + 1)*2;
        result = tmp;
    }
    return result;
}
```