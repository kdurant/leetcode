/*
有一堆石头，每块石头的重量都是正整数。

每一回合，从中选出两块最重的石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。

 

提示：

1 <= stones.length <= 30
1 <= stones[i] <= 1000
在真实的面试中遇到过这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/last-stone-weight
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int lastStoneWeight(int *s, int size)
{
    while(size > 1)
    {
        qsort(s, size, sizeof(int), compare);
        s[size - 2] = s[size - 1] - s[size - 2];
        size--;
    }
    return s[0];
}
int main(void)
{
    int s[] = {3, 4, 4};
    printf("%d\n", lastStoneWeight(s, sizeof(s) / sizeof(int)));
    return 0;
}
