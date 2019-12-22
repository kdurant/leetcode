/*
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

示例 1:

输入:
"abccccdd"

输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <stdbool.h>

int longestPalindrome(char* s)
{
    int table[60] = {0};
    int r         = 0;
    // 统计字符串中字符出现的个数
    for(char* t = s; *t != '\0'; t++)
    {
        table[*t - 'A']++;
    }
    for(int i = 0; i < 60; i++)
    {
        r += (table[i] / 2) * 2;

        // 如果字符个数是奇数，且没有统计过
        if(table[i] % 2 == 1 && r % 2 == 0)
            r++;
    }
    return r;
}

int main(void)
{
    // int nums[] = {3, 0, 1, 4, 2, 1};
    printf("%d\n", longestPalindrome("zeusnilemacaronimaisanitratetartinasiaminoracamelinsuez"));  // 55
    printf("%d\n",
           longestPalindrome(
               "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecomet"
               "odedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatw"
               "eshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehave"
               "consecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydi"
               "dhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobe"
               "herededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullm"
               "easureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgo"
               "vernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth"));
    return 0;
}
