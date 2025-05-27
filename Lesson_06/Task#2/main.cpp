#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() 
{
    int n;
    std::cin >> n;

    std::set<int> uniq;
    for (int i = 0; i < n; ++i) 
    {
        int x;
        std::cin >> x;
        uniq.insert(x);
    }

    std::vector<int> result(uniq.begin(), uniq.end());
    std::sort(result.begin(), result.end(), std::greater<int>());

    for (int x : result) 
    {
        std::cout << x << std::endl;
    }

    return 0;
}
