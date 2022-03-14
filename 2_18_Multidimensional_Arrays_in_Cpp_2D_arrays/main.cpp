#include <iostream>

void part_1()
{
    const int size = 10;
    // int *arr = new int[50];

    int **arr2d = new int *[size];

    for (int i = 0; i < size; i++)
    {
        arr2d[i] = new int[size];
    }

    arr2d[0][0] = 123;
    std::cout << arr2d[0][0] << std::endl;

    int ***arr3d = new int **[size];
    for (int i = 0; i < size; i++)
    {
        arr3d[i] = new int *[size];
        for (int j = 0; j < size; j++)
        {
            // arr3d[i][j] = new int[size];
            int **ptr = arr3d[i];
            ptr[j] = new int[size];
        }
    }

    arr3d[0][0][0] = 123;
    std::cout << arr3d[0][0][0] << std::endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            delete[] arr3d[i][j];
        }
        delete[] arr3d[i];
    }
    delete[] arr3d;

    for (int i = 0; i < size; i++)
    {
        delete[] arr2d[i];
    }
    delete[] arr2d;
}

int main()
{
    const int size_y = 5;
    const int size_x = 5;
    int *arr = new int[size_y * size_x];

    for (int y = 0; y < size_y; y++)
    {
        for (int x = 0; x < size_x; x++)
        {
            arr[(size_y * y) + x] = (size_y * y) + x;
        }
    }

    for (int i = 0; i < size_y * size_x; i++)
    {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}