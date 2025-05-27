#include <iostream>
#include <vector>
#include <algorithm>

void make_unique(std::vector<int>& vec) 
{
    std::sort(vec.begin(), vec.end());
    auto last = std::unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());
}

int main() 
{
    std::vector<int> numbers = { 1, 1, 2, 5, 6, 1, 2, 4 };
    make_unique(numbers);

    for (int n : numbers) 
    {
        std::cout << n << " ";
    }

}
