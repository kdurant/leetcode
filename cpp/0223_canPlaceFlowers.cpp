#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        if(n == 0)
            return true;
        int insert = 0;
        int len    = flowerbed.size();

        for(int i = 0; i < len;)
        {
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == len - 1 || flowerbed[i + 1] == 0))
            {
                flowerbed[i] = 1;
                insert++;
            }
            i++;
        }

        return insert >= n;
    }
};

int main(void)
{
    Solution s;
    // {0, 0, 1}  1
    // vector<int> flowerbed{1, 0, 0, 0, 0, 0, 1};
    // vector<int> flowerbed{1, 0, 0};
    vector<int> flowerbed{0, 0, 1};
    cout << s.canPlaceFlowers(flowerbed, 1) << endl;

    return 0;
}
