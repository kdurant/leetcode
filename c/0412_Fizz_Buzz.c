/*
写一个程序，输出从 1 到 n 数字的字符串表示。

1. 如果 n 是3的倍数，输出“Fizz”；

2. 如果 n 是5的倍数，输出“Buzz”；

3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。

示例：

n = 15,

返回:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fizz-buzz
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char** fizzBuzz(int n, int* returnSize)
{
    *returnSize = n;
    char** r    = (char**)malloc(n * sizeof(char*));
    for(int i = 1; i <= n; i++)
    {
        r[i - 1] = (char*)calloc(10, 1);
        if((i % 15) == 0)
            strcpy(r[i - 1], "FizzBuzz");
        else if((i % 3) == 0)
            strcpy(r[i - 1], "Fizz");
        else if((i % 5) == 0)
            strcpy(r[i - 1], "Buzz");
        else
            sprintf(r[i - 1], "%d", i);
    }
    return r;
}

int main(void)
{
    int    n;
    char** s;
    s = fizzBuzz(5, &n);

    for(int i = 0; i < n; i++)
    {
        printf("%s\n", s[i]);
    }
    return 0;
}
