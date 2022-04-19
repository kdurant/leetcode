/*
https://leetcode-cn.com/problems/detect-capital/

给定一个单词，你需要判断单词的大写使用是否正确。

我们定义，在以下情况时，单词的大写用法是正确的：

全部字母都是大写，比如"USA"。
单词中所有字母都不是大写，比如"leetcode"。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
否则，我们定义这个单词没有正确使用大写字母。

示例 1:

输入: "USA"
输出: True
示例 2:

输入: "FlaG"
输出: False
注意: 输入是由大写和小写拉丁字母组成的非空单词。
*/
#include <stdio.h>
#include <stdbool.h>

bool detectCapitalUse(char * word){
    int mode;
    if( (*word >= 'A') && (*word <= 'Z') )
    {
        if( (*(word+1) >= 'A') && (*(word+1) <= 'Z') )
            mode = 1;
        else
            mode = 3;
    }
    else
        mode = 2;
    
    word++;

    while(*word)
    {
        if(mode == 1)
        {
            if( (*word >= 'A') && (*word <= 'Z') )
                word++;
            else
                return false;
        }
        else if( (mode == 2) || (mode == 3) )
        {
            if( (*word >= 'a') && (*word <= 'z') )
                word++;
            else
                return false;            
        }
    }
    return true;
}

int main()
{
    printf("%d\n", detectCapitalUse("FlaG"));
}