/*
https://leetcode-cn.com/problems/student-attendance-record-i/

给定一个字符串来代表一个学生的出勤记录，这个记录仅包含以下三个字符：

'A' : Absent，缺勤
'L' : Late，迟到
'P' : Present，到场
如果一个学生的出勤记录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),那么这个学生会被奖赏。

你需要根据这个学生的出勤记录判断他是否会被奖赏。

示例 1:

输入: "PPALLP"
输出: True
示例 2:

输入: "PPALLL"
输出: False
*/

#include <stdio.h>
#include <stdbool.h>

bool checkRecord(char * s){
    int a = 0;
    int l_status = 0;
    while(*s != '\0')
    {
        switch(*s)
        {
        case 'A':
            a++;
            if(l_status <= 2)
                l_status = 0;
            break;
        case 'L':
            switch(l_status)
            {
                case 0:
                    l_status = 1;
                    break;
                case 1:
                    l_status = 2;
                    break;
                case 2:
                    l_status = 3;
                    break;
                
                default:
                break;
            }
            break;
        case 'P':
            if(l_status <= 2)
                l_status = 0;
            break;
        default:
        break;
        }
        s++;
    }

    if( a <= 1 && l_status <= 2)
        return true;
    else
        return false;
}



int main()
{
    printf("%d\n", checkRecord("PPALLL"));
}