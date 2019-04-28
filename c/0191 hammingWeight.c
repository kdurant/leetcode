/*
编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

int hammingWeight(uint32_t n) {
    int result = 0;
    for(size_t i = 0; i < 32; i++)
    {
        if( (n >> i) & 0x01 )
            result++;
    }
    return result; 
}
int main()
{
	
	printf("Age size is %d\n", hammingWeight(7));
	return 0;
}