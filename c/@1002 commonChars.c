/*
https://leetcode-cn.com/problems/find-common-characters/

给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。

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
#include <malloc.h>

char ** commonChars(char ** A, int ASize, int* returnSize){
    int c[26] = {0};
    char * s;
    char **res = malloc(sizeof(char *) * 26);
    int len = 0;
    for (size_t i = 0; i < ASize; i++)
    {   
        s = A[i];
        while(*s)
        {
            c[*s-0x61] += 1;
            s++;
        }
    }
    for (size_t i = 0; i < 26; i++)
    {
        if(c[i] != 0 && (c[i] % 3 == 0) )
        {
            *res = (char *)&c[i];
            len++;
        }
    }
    *returnSize = len;
    return res;
}

int main()
{
    char *s[3] = {"bella","label","roller"};
    int returnSize = 3;
    char **t = malloc(sizeof(char *) * 26);
    t = commonChars(s, 3, &returnSize);

    for (int i = 0; i < returnSize; ++i) {
        printf("%s ", t[i]);
    }
}