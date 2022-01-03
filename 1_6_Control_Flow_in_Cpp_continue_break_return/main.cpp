#include <iostream>

void count(int num)
{
    int i = 0;
    while (true)
    {
        std::cout << i << std::endl;
        if (i >= num)
            return;
        i++;
    }
}

int main()
{
    count(5);

    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 1)
            continue;
        std::cout << i << std::endl;
    }

    int i = 0;
    while (true)
    {
        if (i >= 5)
            break;
        std::cout << i << std::endl;
        i++;
    }

    return 0;
}