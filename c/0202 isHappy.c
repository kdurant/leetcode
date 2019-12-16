/*
编写一个算法来判断一个数是不是“快乐数”。

一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到
1。如果可以变为 1，那么这个数就是快乐数。

示例: 

输入: 19
输出: true
解释:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/happy-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

int cal(int n)
{
    int res = 0;
    do
    {
        int tail = n % 10;
        res += (tail * tail);
        n /= 10;
    } while(n);
    return res;
}

bool isHappy(int n)
{
    int          i;
    unsigned int idx      = 0;
    int          result   = 0;
    bool         se[1000] = {false};

    n = cal(n);
    while(!se[n])
    {
        se[n] = true;
        n     = cal(n);
    }
    return n == 1;
}

int main(void)
{
    assert(isHappy(1111111));
    assert(isHappy(19));
    assert(isHappy(1));
    assert(!isHappy(2));
    // printf("%d\n", isHappy(19));
    // printf("%d\n", isHappy(1));
    // printf("%d\n", isHappy(2));
    // printf("%d\n", isHappy(1111111));

    return 0;
}
