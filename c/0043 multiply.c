/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/multiply-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void reverseString2(char* s, int sSize)
{
    int i = 0;
    int j = sSize - 1;
    int tmp;
    while(i < j)
    {
        tmp  = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}
char* multiply(char* num1, char* num2)
{
    char  data[220] = {0};
    int   num1_len  = strlen(num1);
    int   num2_len  = strlen(num2);
    char* ret       = calloc(num1_len + num2_len + 1, sizeof(char));
    int   idx       = 0;
    if(*num1 == '0' || *num2 == '0')
        return "0";

    int mod        = 0;
    int remain     = 0;
    int mul_result = 0;
    int add_result = 0;
    int carry      = 0;
    for(int i = num1_len - 1; i >= 0; i--)
    {
        for(int j = num2_len - 1; j >= 0; j--)
        {
            mul_result = (num1[i] - 0x30) * (num2[j] - 0x30);
            mod        = mul_result % 10;
            if(ret[idx] >= 0x30)
                ret[idx] -= 0x30;
            add_result = ret[idx] + remain + mod + carry;
            ret[idx]   = add_result % 10 + 0x30;

            remain = mul_result / 10;
            carry  = add_result / 10;
            idx++;
        }
        if(remain + carry > 0)
            ret[idx] = remain + carry + 0x30;
        else
            ret[idx] = remain + carry;
        idx    = num1_len - i;
        remain = 0;
        carry  = 0;
    }
    reverseString2(ret, strlen(ret));
    return ret;
}

int main(void)
{
    printf("%s\n", multiply("123", "456"));
    printf("%s\n", multiply("456", "123"));
    printf("%s\n", multiply("456", "10"));
    printf("%s\n", multiply("10", "456"));

    return 0;
}
