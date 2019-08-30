/*
https://leetcode-cn.com/problems/find-common-characters/

给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3
次，但不是 4 次，则需要在最终答案中包含该字符 3 次。

你可以按任意顺序返回答案。



示例 1：

输入：["bella","label","roller"]
输出：["e","l","l"]
示例 2：

输入：["cool","lock","cook"]
输出：["c","o"]


提示：

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] 是小写字母
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char** commonChars(char** A, int ASize, int* returnSize)
{
    int data[26] = {0};
    int idx      = 0;

    for(int i = 0; i < ASize; i++)
    {
        char* s = A[i];
        while(*s)
        {
            data[*s - 'a'] += 1;

            if(data[*s - 'a'] > i + 1)
                data[*s - 'a'] = i + 1;
            s++;
        }
    }

    char** r = malloc(26 * sizeof(char*));

    for(int i = 0; i < 26; i++)
    {
        if(data[i] == 3)
        {
            r[idx]    = (char*)malloc(sizeof(char) * 2);
            r[idx][0] = i + 'a';
            r[idx][1] = '\0';
            idx++;
        }
    }
    *returnSize = idx;
    return r;
}

int main(void)
{
    char*  s[3] = {"bella", "label", "roller"};
    int    col;
    char** r = commonChars(s, 3, &col);

    for(int i = 0; i < col; i++)
    {
        puts(r[i]);
    }
    return 0;
}
