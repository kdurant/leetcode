/*
给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

示例 1:

输入: 2
输出: [0,1,1]
示例 2:

输入: 5
输出: [0,1,1,2,1,2]
进阶:

给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？
要求算法的空间复杂度为O(n)。
你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/counting-bits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <stdio.h>
#include <stdlib.h>

int* countBits(int num, int* returnSize)
{
    int* ret = malloc((num + 1) * sizeof(int));
    printf("malloc ret address %p\n", ret);
    ret[0]      = 0;
    *returnSize = num + 1;

    for(int i = 1; i <= num; i++)
    {
        int temp = i;
        while(temp)
        {
            switch(i & 0x0f)
            {
                case 0:
                    ret[i] += 0;
                    break;
                case 1:
                case 2:
                case 4:
                case 8:
                    ret[i] += 1;
                    break;
                case 3:
                case 5:
                case 6:
                case 9:
                case 10:
                case 11:
                case 13:
                    ret[i] += 2;
                    break;
                case 7:
                case 12:
                case 14:
                    ret[i] += 3;
                    break;
                case 15:
                    ret[i] += 4;
                    break;
                default:
                    break;
            }
            temp = temp >> 4;
        }
    }
    return ret;
}

int main(void)
{
    int  returnSize;
    int* ret = countBits(3, &returnSize);
    printf("assign ret address %p\n", ret);
    for(int i = 0; i < returnSize; i++)
    {
        printf("%d\n", ret[i]);
    }
    free(ret);

    return 0;
}
