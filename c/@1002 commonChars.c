/*
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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-common-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char** commonChars(char** A, int ASize, int* returnSize)
{
    int(*counter)[26];
    char*  p;
    int    i, j;
    char** result;

    counter = (int(*)[26])calloc(ASize, 26 * sizeof(int));
    for(i = 0; i < ASize; i++)
    {
        p = A[i];
        while(*p)
        {
            counter[i][*p - 'a']++;
            p++;
        }
    }

    for(j = 0; j < 26; j++)
    {
        if(!counter[0][j])
            continue;
        for(i = 1; i < ASize; i++)
        {  // find min
            if(counter[i][j] < counter[0][j])
                counter[0][j] = counter[i][j];
        }
    }

    *returnSize = 0;
    for(j = 0; j < 26; j++)
    {
        if(counter[0][j])
            (*returnSize) += counter[0][j];
    }

    result = (char**)malloc(*returnSize * sizeof(char*));
    i      = 0;
    for(j = 0; j < 26; j++)
    {
        while(counter[0][j]--)
        {
            result[i]    = (char*)calloc(2, sizeof(char));
            result[i][0] = j + 'a';
            i++;
        }
    }
    return result;
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
