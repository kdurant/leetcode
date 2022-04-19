/*
https://leetcode-cn.com/problems/first-unique-character-in-a-string/

给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:
s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
 
注意事项：您可以假定该字符串只包含小写字母。
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int firstUniqChar(char * s){
    int flag[26] = {0};
    char *save = s;
    while(*s != 0)
    {
        flag[*s-0x61] += 1;
        s++;
    }
    int idx = 0;
    s = save;
    while (*s != 0)
    {
        if(flag[*s - 0x61] == 1)
            return idx;
        s++;
        idx++;
    }
    return -1;
    
}


int main()
{
    printf("%d\n", firstUniqChar(""));
    return 0;
} 