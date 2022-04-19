/*
请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。

通过次数155,577

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/daily-temperatures
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <iostream>
#include <string>
#include <ctype.h>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int         n = temperatures.size();
        vector<int> ans(n);
        stack<int>  indices;

        for(int i = 0; i < n; ++i)
        {
            while(!indices.empty())
            {
                int pre_index = indices.top();  // 取出需要比较的index
                if(temperatures[i] <= temperatures[pre_index])
                    break;
                indices.pop();  // 如果后面有大的，及时处理
                ans[pre_index] = i - pre_index;
            }
            indices.push(i);  // 往栈里压入一个带比较的index
        }

        return ans;
    }
};

int main(int argc, char* argv[])
{
    Solution    s;
    vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ret = s.dailyTemperatures(temperatures);
    for(auto& i : ret)
        cout << i << '\t';
    return 0;
}
