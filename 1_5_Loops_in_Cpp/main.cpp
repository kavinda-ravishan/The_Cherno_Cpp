#include <iostream>
#include <string>

template <typename T>
void print(T i, std::string text)
{
    std::cout << i << ". " << text << std::endl;
}

int main()
{
    int i;

    for (i = 0; i < 5; i++)
    {
        print(i, "for loop");
    }

    i = 0;
    for (;;)
    {
        if (i == 5)
            break;
        print(i, "for while loop");
        i++;
    }

    i = 0;
    while (i < 5)
    {
        print(i, "while loop");
        i++;
    }

    i = 0;
    do
    {
        print(i, "do while loop");
        i++;
    } while (i < 5);

    return 0;
}