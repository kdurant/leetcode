/*
给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 -1 替换。

完成所有替换操作后，请你返回这个数组。


示例：

输入：arr = [17,18,5,4,6,1]
输出：[18,6,6,6,1,-1]
 

提示：

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/replace-elements-with-greatest-element-on-right-side
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
    vector<int> replaceElements(vector<int>& arr)
    {
        int len = arr.size();
        int max = arr[len - 1];
        for(int i = len - 2; i >= 0; i--)
        {
            int temp = arr[i];
            arr[i]   = max;
            if(temp > max)
                max = temp;
        }
        arr[len - 1] = -1;
        return arr;
    }
};

int main(void)
{
    Solution    sol;
    vector<int> arr = {17, 18, 5, 4, 6, 1};
    arr             = sol.replaceElements(arr);
    for(size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}