/*
给定一个Excel表格中的列名称，返回其相应的列序号。

例如，

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    ...
示例 1:

输入: "A"
输出: 1
示例 2:

输入: "AB"
输出: 28
示例 3:

输入: "ZY"
输出: 701

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/excel-sheet-column-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int titleToNumber(char* s)
{
    int r   = 0;
    int len = strlen(s);
    int value;
    for(int i = len - 1; i >= 0; i--)
    {
        value = (*(s + i) - 'A') + 1;
        // value = value * 26 * (len - 1 - i);
        value = pow(26, len - 1 - i) * value;

        r += value;
    }
    return r;
}
int main(void)
{
    printf("%d\n", titleToNumber("AB"));
    printf("%d\n", titleToNumber("AC"));
    printf("%d\n", titleToNumber("ZY"));
    return 0;
}

