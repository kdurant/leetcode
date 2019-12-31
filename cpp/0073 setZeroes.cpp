/*
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

示例 1:

输入:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2:

输入:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
进阶:

一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个常数空间的解决方案吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/set-matrix-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        vector<vector<int>> save(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < matrix.size(); i++)  // 行
        {
            for(int j = 0; j < matrix[i].size(); j++)  // 列
            {
                if(matrix[i][j] == 0)
                {
                    save[i][j] = 1;
                }
            }
        }

        for(int i = 0; i < matrix.size(); i++)  // 行
        {
            for(int j = 0; j < matrix[i].size(); j++)  // 列
            {
                if(save[i][j] == 1)
                {
                    for(int m = 0; m < matrix[i].size(); m++)  // clear 行
                        matrix[i][m] = 0;
                    for(int m = 0; m < matrix.size(); m++)
                        matrix[m][j] = 0;
                }
            }
        }
    }
};

int main()
{
    Solution            s;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    s.setZeroes(matrix);
    for(size_t i = 0; i < matrix.size(); i++)
    {
        for(size_t j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}