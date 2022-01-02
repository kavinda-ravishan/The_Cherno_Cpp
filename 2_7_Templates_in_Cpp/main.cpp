#include <iostream>
#include <string>

class Name
{
public:
    std::string name{"kavinda"};
};

template <class Obj>
class Print
{
private:
    Obj *obj;

public:
    Print()
    {
        obj = new Obj;
        std::cout << obj->name << std::endl;
        delete obj;
    }
};

template <typename T, int size>
class Array
{
private:
    T _array[size];

public:
    Array()
    {
        for (int i = 0; i < size; i++)
        {
            _array[i] = i * i;
        }
    }
    void printArray() const
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << _array[i] << std::endl;
        }
    }
};

template <typename T, typename N>
void print(T value, N n)
{
    std::cout << n << ". " << value << std::endl;
}

template <int size>
void printArray(int *arr)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << *(arr + i) << std::endl;
    }
}

int main()
{
    print(12, 2);
    print(12.2f, 3);
    print<std::string, int>("hello", 4);

    Print<Name> p;

    Array<int, 5> array;
    array.printArray();

    int arr[] = {1, 3, 5, 6};
    printArray<sizeof(arr) / sizeof(int)>(arr);

    return 0;
}