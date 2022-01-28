#include <iostream>

class Entity
{
    static const int size = 5;
    int arr[size];
};

int main()
{
    // stack

    int arr[5];
    arr[0] = 2;
    arr[4] = 4;

    std::cout << arr[0] << std::endl;

    for (int i = 0; i < 5; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << std::endl;
    }

    int *pArr = arr;

    *(pArr + 2) = 123;
    std::cout << arr[2] << std::endl;
    std::cout << pArr[2] << std::endl;

    *(int *)((char *)pArr + 8) = 456;

    std::cout << arr[2] << std::endl;
    std::cout << pArr[2] << std::endl;

    // heep
    int *arrh = new int[5];

    for (int i = 0; i < 5; i++)
    {
        arrh[i] = i;
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << arrh[i] << std::endl;
    }
    std::cout << sizeof(arr) / sizeof(int) << std::endl;

    delete[] arrh;

    return 0;
}