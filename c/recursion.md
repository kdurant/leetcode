对于递归的程序，有两个要求：

1. 子问题需与原始问题为同样的事，且更为简单；
2. 不能无限制地调用本身，需有个出口，化简为非递归状况处理。

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
2. `n=1`时，跳出递归

# 阶乘

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