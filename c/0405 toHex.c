/*
https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/

给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。

注意:

十六进制中所有字母(a-f)都必须是小写。
十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。 
给定的数确保在32位有符号整数范围内。
不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。
示例 1：

输入:
26

输出:
"1a"
示例 2：

输入:
-1

输出:
"ffffffff"
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * toHex(int num){
    char *r = malloc(sizeof(char) * (8+1));
    memset(r, 0, 9);
    int cnt = 0;
    char ch;
    if(num == 0)
    {
        r[0] = '0';
        return r;
    }
    while(num != 0)
    {
        switch(num & 0x0f)
        {
        case 0:
            ch = '0';
            break;
        case 1:
            ch = '1';
            break;
        case 2:
            ch = '2';
            break;
        case 3:
            ch = '3';
            break;
        case 4:
            ch = '4';
            break;
        case 5:
            ch = '5';
            break;
        case 6:
            ch = '6';
            break;
        case 7:
            ch = '7';
            break;
        case 8:
            ch = '8';
            break;
        case 9:
            ch = '9';
            break;
        case 10:
            ch = 'a';
            break;
        case 11:
            ch = 'b';
            break;
        case 12:
            ch = 'c';
            break;
        case 13:
            ch = 'd';
            break;
        case 14:
            ch = 'e';
            break;
        case 15:
            ch = 'f';
            break;
        default:
        break;
        }
        r[7-cnt] = ch;
        cnt++;
        num = (num >> 4) & 0x0fffffff;
    }

    return r+8-cnt;
}

int main()
{
    printf("%s\n", toHex(0));
}