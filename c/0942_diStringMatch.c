/*
给定只含 "i"（增大）或 "d"（减小）的字符串 s ，令 n = s.length。

返回 [0, 1, ..., n] 的任意排列 a 使得对于所有 i = 0, ..., n-1，都有：

如果 s[i] == "i"，那么 a[i] < a[i+1]
如果 s[i] == "d"，那么 a[i] > a[i+1]
 

示例 1：

输出："idid"
输出：[0,4,1,3,2]
示例 2：

输出："iii"
输出：[0,1,2,3]
示例 3：

输出："ddi"
输出：[3,2,0,1]
 

提示：

1 <= s.length <= 1000
s 只包含字符 "i" 或 "d"。
在真实的面试中遇到过这道题？

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/di-string-match
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int *distringmatch(char *s, int *returnsize)
{
    int  len = strlen(s);
    int *ans = malloc((len + 1) * sizeof(int));

    int *p   = ans;
    int  min = 0;
    int  h   = len;

    for(int i = 0; i < len; i++, p++)
    {
        if(s[i] == 'i')
            *p = min++;
        else
            *p = h--;
    }
    *p          = min;
    *returnsize = len + 1;
    return ans;
}

int main(void)
{
    char s[4] = {'i', 'd', 'i', 'd'};
    int  ret;
    int *p;

    p = distringmatch(s, &ret);

    for(int i = 0, len = sizeof(*p); i < len; i++)
    {
        printf("p[%d] = %d \n", i, *(p + i));
    }
    return 0;
}
