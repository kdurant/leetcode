/*
给你两个数组，arr1 和 arr2，

arr2 中的元素各不相同
arr2 中的每个元素都出现在 arr1 中
对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。

 

示例：

输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
输出：[2,2,2,1,4,3,3,9,6,7,19]
 

提示：

arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
arr2 中的元素 arr2[i] 各不相同
arr2 中的每个元素 arr2[i] 都出现在 arr1 中

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/relative-sort-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int>   res;
        map<int, int> m;
        for(auto n : arr1)
            m[n]++;
        for(auto a : arr2)
        {
            while(m[a]--)
                res.push_back(a);
            m.erase(a);
        }
        for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
        {
            while((it->second)--)
                res.push_back(it->first);
        }
        return res;
    }
};

int main(void)
{
    Solution    sol;
    vector<int> arr1 = {28, 6, 22, 8, 44, 17};
    vector<int> arr2 = {22, 28, 8, 6};

    arr1 = sol.relativeSortArray(arr1, arr2);
    for(size_t i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << endl;
    }
    return 0;
}