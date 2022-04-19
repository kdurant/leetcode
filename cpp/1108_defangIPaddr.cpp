/*
给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。

所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。

 

示例 1：

输入：address = "1.1.1.1"
输出："1[.]1[.]1[.]1"
示例 2：

输入：address = "255.100.50.0"
输出："255[.]100[.]50[.]0"
 

提示：

给出的 address 是一个有效的 IPv4 地址

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/defanging-an-ip-address
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
    string defangIPaddr(string address)
    {
        string s;
        for(int i = 0; i < address.size(); i++)
        {
            if(address[i] == '.')
                s.append("[.]");
            else
                s.append(1, address[i]);
        }

        return s;
    }
};

int main(void)
{
    Solution sol;

    cout << sol.defangIPaddr("192.168.1.1");
}
