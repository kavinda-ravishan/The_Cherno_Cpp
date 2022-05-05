#include <iostream>

void example_1()
{
    int a = 12;
    float &b = *(float *)&a;

    std::cout << b << std::endl;
}

struct Entity
{
    int x, y;
};

int main()
{
    Entity e = {5, 8};

    int &x = *(int *)&e;
    int &y = *((int *)&e + 1);
    std::cout << "x : " << x << ", y : " << y << std::endl;

    int *arr = (int *)&e;
    std::cout << "x : " << arr[0] << ", y : " << arr[1] << std::endl;

    return 0;
}