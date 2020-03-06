#include <vector>

class Solution
{
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        int result = 0;
        int col    = grid[0].size();
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] < 0)
                {
                    result += (col - j);
                    break;
                }
            }
        }
        return result;
    }
};