/*
统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int countPrimes(int n)
{
    if(n < 2)
        return 0;

    unsigned char *hash = calloc(n, 1);

    hash[0] = 1;
    hash[1] = 1;

    int res = 0;
    int i;

    for(i = 2; i * i < n; i++)
    // for(i = 2; i <= (int)sqrt(n) + 1; i++)
    {
        if(hash[i] == 1)
            continue;

        for(int j = 2 * i; j < n; j += i)
            hash[j] = 1;
    }

    for(i = 0; i < n; i++)
    {
        if(hash[i] == 0)
            res++;
    }
    return res;
}

int main(void)
{
    assert(countPrimes(10) == 4);
    assert(countPrimes(20) == 8);
    assert(countPrimes(30) == 10);
    assert(countPrimes(100) == 25);
    assert(countPrimes(10000) == 1229);
    assert(countPrimes(499979) == 41537);
    printf("%d\n", countPrimes(999983));   // 78497
    printf("%d\n", countPrimes(1500000));  // 114155

    return 0;
}