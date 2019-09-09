/*
公司计划面试 2N 人。第 i 人飞往 A 市的费用为 costs[i][0]，飞往 B 市的费用为 costs[i][1]。

返回将每个人都飞到某座城市的最低费用，要求每个城市都有 N 人抵达。

 

示例：

输入：[[10,20],[30,200],[400,50],[30,20]]
输出：110
解释：
第一个人去 A 市，费用为 10。
第二个人去 A 市，费用为 30。
第三个人去 B 市，费用为 50。
第四个人去 B 市，费用为 20。

最低总费用为 10 + 30 + 50 + 20 = 110，每个城市都有一半的人在面试。
 

提示：

1 <= costs.length <= 100
costs.length 为偶数
1 <= costs[i][0], costs[i][1] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-city-scheduling
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void* pa, const void* pb)
{
    int** ptra = (int**)pa;
    int** ptrb = (int**)pb;
    int*  a    = *ptra;
    int*  b    = *ptrb;
    return ((a[0] - a[1]) - (b[0] - b[1]));
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize)
{
    int res         = 0;
    int costsLength = costsSize / 2;
    qsort(costs, costsSize, sizeof(int*), compare);
    for(int i = 0; i < costsLength; i++)
    {
        res += (costs[i][0] + costs[i + costsLength][1]);
    }
    return res;
}

//{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}
int main(void)
{
    int  d1[2]    = {259, 770};
    int  d2[2]    = {448, 54};
    int  d3[2]    = {926, 667};
    int  d4[2]    = {184, 139};
    int  d5[2]    = {840, 118};
    int  d6[2]    = {577, 469};
    int* costs[6] = {d1, d2, d3, d4, d5, d6};
    int  col;
    // printf("%d\n", sizeof(costs) / sizeof(costs[0]));
    printf("%d\n", twoCitySchedCost(costs, sizeof(costs) / sizeof(costs[0]), &col));
    return 0;
}

