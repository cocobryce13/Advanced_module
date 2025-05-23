#include <iostream>
#include <vector>

template <typename T>
class Table 
{
private:
    std::vector<std::vector<T>> data;

public:
    Table(size_t rows, size_t cols) : data(rows, std::vector<T>(cols)) {}

    std::vector<T>& operator[](size_t row) 
    {
        return data[row];
    }

    const std::vector<T>& operator[](size_t row) const 
    {
        return data[row];
    }

    std::pair<size_t, size_t> Size() const 
    {
        if (data.empty()) 
        {
            return { 0, 0 };
        }
        return { data.size(), data[0].size() };
    }
};

int main() 
{
    Table<int> test(2, 3);

    test[0][0] = 4;
    std::cout << test[0][0] << std::endl;

    auto size = test.Size();
    std::cout << "Rows: " << size.first << ", Cols: " << size.second << std::endl;

    return 0;
}