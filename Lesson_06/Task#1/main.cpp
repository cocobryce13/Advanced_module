#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main() 
{
    std::string text;
    std::getline(std::cin, text); 
    std::map<char, int> freq;

    for (char c : text) 
    {
        freq[c]++;
    }

    std::vector<std::pair<char, int>> sorted(freq.begin(), freq.end());

    std::sort(sorted.begin(), sorted.end(), [](auto& a, auto& b) 
        {
        return a.second > b.second;
        });

    for (auto& pair : sorted) 
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
