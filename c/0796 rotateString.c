/*
给定两个字符串, A 和 B。

A 的旋转操作就是将 A 最左边的字符移动到最右边。 例如, 若 A =
'abcde'，在移动一次之后结果就是'bcdea' 。如果在若干次旋转操作之后，A 能变成B，那么返回True。

示例 1:
输入: A = 'abcde', B = 'cdeab'
输出: true

示例 2:
输入: A = 'abcde', B = 'abced'
输出: false
注意：

A 和 B 长度不超过 100。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool rotateString(char* A, char* B)
{
    int len = strlen(A);
    if((strlen(A) == 0) && (strlen(B) == 0))
        return true;
    int   i = 0;
    char* s = calloc(len + 1, sizeof(char));

    // nihao
    while(i < len)
    {
        strncpy(s, A + i, len - i);  //
        strncpy(s + len - i, A, i);
        i++;
        if(strcmp(s, B) == 0)
            return true;
    }
    return false;
}

int main(void)
{
    char A[] = "abcde";
    char B[] = "cdeab";
    printf("%d\n", rotateString(A, B));
    return 0;
}
