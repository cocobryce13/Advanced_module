#include <iostream>
#include <windows.h>

class smart_array 
{
private:
    int* data;
    int capacity;
    int size;

public:
    smart_array(int cap) 
    {
        if (cap <= 0) 
        {
            std::cout << "Неверный размер. Устанавливаю размер 10 по умолчанию." << std::endl;
            cap = 10;
        }
        capacity = cap;
        size = 0;
        data = new int[capacity];
    }

    smart_array(const smart_array& other) 
    {
        capacity = other.capacity;
        size = other.size;
        data = new int[capacity];
        for (int i = 0; i < size; ++i) 
        {
            data[i] = other.data[i];
        }
    }

    smart_array& operator=(const smart_array& other) 
    {
        if (this == &other) 
        {
            return *this;
        }

        delete[] data;

        capacity = other.capacity;
        size = other.size;
        data = new int[capacity];
        for (int i = 0; i < size; ++i) 
        {
            data[i] = other.data[i];
        }

        return *this;
    }

    void add_element(int value) 
    {
        if (size >= capacity) 
        {
            std::cout << "Ошибка: массив переполнен, нельзя добавить элемент." << std::endl;
            return;
        }
        data[size] = value;
        size++;
    }

    int get_element(int index) const 
    {
        if (index < 0 || index >= size) 
        {
            std::cout << "Ошибка: индекс вне диапазона." << std::endl;
            return -1;
        }
        return data[index];
    }

    ~smart_array() 
    {
        delete[] data;
    }
};


int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array;

    std::cout << arr.get_element(0) << std::endl;
    std::cout << arr.get_element(1) << std::endl;

    return 0;
}
