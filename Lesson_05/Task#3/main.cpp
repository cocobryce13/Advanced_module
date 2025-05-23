#include <iostream>
#include <vector>
#include <algorithm>

class Counter 
{
private:
    int sum_ = 0;
    int count_ = 0;

public:
    void operator()(int num) 
    {
        if (num % 3 == 0) 
        {
            sum_ += num;
            count_++;
        }
    }

    int get_sum() const { return sum_; }
    int get_count() const { return count_; }
};

int main() 
{
    std::vector<int> numbers;
    int num;

    while (std::cin >> num) 
    {
        numbers.push_back(num);
    }

    Counter counter = std::for_each(numbers.begin(), numbers.end(), Counter());

    std::cout << "get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "get_count() = " << counter.get_count() << std::endl;

    return 0;
}