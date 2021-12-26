#include <iostream>

int main()
{
    for (int i = 1; i < 10; i++)
    {
        bool isEven = (i % 2) == 0;
        if (isEven)
            std::cout << i << " is even." << std::endl;
        else
            std::cout << i << " is odd." << std::endl;
    }

    return 0;
}