/*
https://leetcode-cn.com/problems/height-checker/

学校在拍年度纪念照时，一般要求学生按照 非递减 的高度顺序排列。

请你返回至少有多少个学生没有站在正确位置数量。该人数指的是：能让所有学生以 非递减 高度排列的必要移动人数。

 

示例：

输入：[1,1,4,2,1,3]
输出：3
解释：
高度为 4、第3个 和最后一个 1 的学生，没有站在正确的位置。
 

提示：

1 <= heights.length <= 100
1 <= heights[i] <= 100

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

int compare(void * data1, void * data2)
{
    return( *(int *)data1 - *(int*)data2);
}

int heightChecker(int* heights, int heightsSize){
    int *res = malloc(sizeof(int) * heightsSize);
    memcpy(res, heights, heightsSize*sizeof(int));
    qsort(res, heightsSize, sizeof(int), compare);

    int result = 0;
    for (size_t i = 0; i < heightsSize; i++)
    {
        result += (res[i] != heights[i]);
    }
    return result; 
}

int main()
{
    int A[] = {1,1,4,2,1,3};

    printf("%d\n", heightChecker(A, sizeof(A)/4));
}