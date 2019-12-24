/*
给定一副牌，每张牌上都写着一个整数。

此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：

每组都有 X 张牌。
组内所有的牌上都写着相同的整数。
仅当你可选的 X >= 2 时返回 true。

 

示例 1：

输入：[1,2,3,4,4,3,2,1]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
示例 2：

输入：[1,1,1,2,2,2,3,3]
输出：false
解释：没有满足要求的分组。
示例 3：

输入：[1]
输出：false
解释：没有满足要求的分组。
示例 4：

输入：[1,1]
输出：true
解释：可行的分组是 [1,1]
示例 5：

输入：[1,1,2,2,2,2]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[2,2]

提示：

1 <= deck.length <= 10000
0 <= deck[i] < 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>

int compare(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if(arg1 < arg2)
        return -1;
    if(arg1 > arg2)
        return 1;
    return 0;
}

bool hasGroupsSizeX(int* deck, int deckSize)
{
    if(deckSize <= 1)
        return false;
    qsort(deck, deckSize, sizeof(int), compare);
    int space = 0;
    for(int i = 0; i < deckSize; i++)
    {
        space++;
        if(deck[i] != deck[i + 1])
            break;
    }

    int num = 0;
    while(deckSize > 0)
    {
        if(deckSize < space)
            return false;

        if(deck[num] != deck[num + space - 1])
            return false;
        else
        {
            num += space;
            deckSize -= space;
        }
    }
    return true;
}

int main(void)
{
    int deck[] = {1, 1};
    printf("%d\n", hasGroupsSizeX(deck, sizeof(deck) / sizeof(deck[0])));
    return 0;
}
