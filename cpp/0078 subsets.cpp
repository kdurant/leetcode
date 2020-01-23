#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
private:
    void generate(int i, vector<int>& nums, vector<int>& item, vector<vector<int>>& res)
    {
        if(i == nums.size())
            return;

        item.push_back(nums[i]);
        res.push_back(item);
        generate(i + 1, nums, item, res);
        item.pop_back();
        generate(i + 1, nums, item, res);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int>         item;
        res.push_back(item);
        generate(0, nums, item, res);
        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution            s;
    vector<int>         nums = {1, 2, 3, 4};
    vector<vector<int>> res;

    res = s.subsets(nums);

    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}
