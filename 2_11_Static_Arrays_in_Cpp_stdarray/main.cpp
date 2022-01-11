#include <iostream>
#include <array>

template <int size>
void printArray(const std::array<int, size> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

int main()
{
    std::array<int, 5> arr = {1, 7, 3, 4, 5};
    arr[arr.size() - 1] = 12;

    for (int num : arr)
    {
        std::cout << num << std::endl;
    }

    printArray<arr.size()>(arr);

    return 0;
}