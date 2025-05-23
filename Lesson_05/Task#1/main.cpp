#include <iostream>
#include <vector>

template <typename T>
T Square(T value) 
{
    return value * value;
}

template <typename T>
std::vector<T> Square(const std::vector<T>& vec) 
{
    std::vector<T> result;
    for (const T& item : vec) 
    {
        result.push_back(Square(item));
    }
    return result;
}

template <typename T>
void PrintVector(const std::vector<T>& vec) 
{
    for (size_t i = 0; i < vec.size(); ++i) 
    {
        std::cout << vec[i];
        if (i + 1 < vec.size()) 
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int main() 
{
    int x = 4;
    std::cout << "[IN]: " << x << std::endl;
    std::cout << "[OUT]: " << Square(x) << std::endl;

    std::vector<int> v = { -1, 4, 8 };
    std::cout << "[IN]: ";
    PrintVector(v);

    std::vector<int> squared = Square(v);
    std::cout << "[OUT]: ";
    PrintVector(squared);

    return 0;
}
