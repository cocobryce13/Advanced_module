#include <iostream>

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

    int get_element(int index) 
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
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) 
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
