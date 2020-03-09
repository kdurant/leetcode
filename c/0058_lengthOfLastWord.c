/*
给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指由字母组成，但不包含任何空格的字符串。

示例:

输入: "Hello World"
输出: 5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/length-of-last-word
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int lengthOfLastWord(char* s)
{
    int result = 0;
    int len    = strlen(s);
    int idx    = 0;
    if(strlen(s))
    {
        char* t = s + len - 1;

        for(int i = 0; i < len; i++)
        {
            if(*(t - i) == ' ')
                idx++;
            else
                break;
        }

        for(int i = 0; i < len - idx; i++)
        {
            if(*(t - idx - i) == ' ')
                return result;
            else
                result++;
        }
        return result;
    }
    else
        return result;
}
int main(void)
{
    printf("%d\n", lengthOfLastWord("Hello World"));
    printf("%d\n", lengthOfLastWord(""));
    printf("%d\n", lengthOfLastWord(" "));
    printf("%d\n", lengthOfLastWord("a "));
    printf("%d\n", lengthOfLastWord("b  a  "));

    return 0;
}
