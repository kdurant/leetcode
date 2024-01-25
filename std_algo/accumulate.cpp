#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> v{ 1, 2, 3, 4, 5};

    // accumulate the sum of the elements in v
    int sum = std::accumulate(v.begin(), v.end(), 1);
    std::cout << "sum: " << sum << std::endl;

    // accumulate the product of the elements in v
    int product = std::accumulate(v.begin(), v.end(), 2, std::multiplies<int>());
    std::cout << "product: " << product << std::endl;

    return 0;
}