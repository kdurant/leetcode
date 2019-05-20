/*
https://leetcode-cn.com/problems/hamming-distance/

两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

给出两个整数 x 和 y，计算它们之间的汉明距离。

注意：
0 ≤ x, y < 231.

示例:

输入: x = 1, y = 4

输出: 2

解释:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

上面的箭头指出了对应二进制位不同的位置。
*/
#include <stdio.h>

int hammingDistance(int x, int y){
    int d = 0;
    int t = x ^ y;
    for (size_t i = 0; i < 32; i++)
    {
        if((t>>i) & 0x01)
            d++;
    }
    return d;
}


int main()
{
    printf("%d\n", hammingDistance(2, 4));
}