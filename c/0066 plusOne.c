/*
https://leetcode-cn.com/problems/plus-one/

给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>


int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *r = malloc((digitsSize+1)*sizeof(int));
    int carry = 0;
    
    for (int i = digitsSize-1; i >= 0; i--)
    {
        if(i == digitsSize-1)
        {
            carry = (digits[i] + 1 + carry) / 10;
            digits[i] = (digits[i] + 1) % 10;
        }
        else
        {
            if( digits[i] + carry == 10)
            {
                carry = 1;
                digits[i] = 0;
            }
            else
            {
                digits[i] += carry;
                carry = 0;
            }
        }
        r[i+1] =  digits[i];
    }
    if(carry)
    {
        r[0] = 1;
        *returnSize = digitsSize + 1;
        return r;
    }
    else
    {
        *returnSize = digitsSize;
        return r+1;
    }
}


int main()
{
    int A[] = {8,9,9,9};
    int size;
    int * r;
    r = plusOne(A, 4, &size);
    
    for (size_t i = 0; i < size; i++)
    {
        printf("%d\t", r[i]);
    }
    
    return 0;
} 