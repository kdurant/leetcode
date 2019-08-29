/*
给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。

 



 

示例：

输入: ["Hello", "Alaska", "Dad", "Peace"]
输出: ["Alaska", "Dad"]
 

注意：

你可以重复使用键盘上同一字符。
你可以假设输入的字符串将只包含字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/keyboard-row
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char** findWords(char** words, int wordsSize, int* returnSize)
{
    char* line1 = "qwertyuiop";
    char* line2 = "asdfghjkl";
    char* line3 = "zxcvbnm";

    int  char_in_line_num = 0;
    char in_line_flag;

    char** r    = malloc(wordsSize * sizeof(char*));
    int    line = 0;

    for(int i = 0; i < wordsSize; i++)
    {
        char* w      = words[i];
        int   pos    = 0;
        int*  record = malloc((strlen(w) + 1) * sizeof(int));
        in_line_flag = true;

        while(*w)  // 记录单词中每个字符所在的行
        {
            char ch = *w;
            if(ch >= 'A' && ch <= 'Z')  // 大写变小写
                ch = *w + ('a' - 'A');

            if(strchr(line1, ch) != NULL)
                char_in_line_num = 1;
            else if(strchr(line2, ch) != NULL)
                char_in_line_num = 2;
            else if(strchr(line3, ch) != NULL)
                char_in_line_num = 3;
            else
                char_in_line_num = 10;
            record[pos++] = char_in_line_num;
            w++;
        }
        //检查每个字符所在行是否一致
        for(int j = 1; j < strlen(words[i]); j++)
        {
            if(record[0] != record[j])
            {
                in_line_flag = false;
                break;
            }
        }

        if(in_line_flag)
        {
            r[line] = malloc((strlen(words[i]) + 1) * sizeof(char));
            strcpy(r[line], words[i]);
            line++;
        }
        free(record);
    }
    *returnSize = line;

    return r;
}

int main(void)
{
    char*  words[] = {"Hello", "Alaska", "Dad", "Peace"};
    int    size;
    char** r = findWords(words, 4, &size);

    for(int i = 0; i < size; i++)
    {
        puts(r[i]);
    }
    return 0;
}

