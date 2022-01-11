#include <iostream>

const char *s_Variable = "s_Variable in Main";
extern const char *variable;

void s_print()
{
    std::cout << "S_Print in Main\n";
}

void print();

int main()
{
    std::cout << s_Variable << std::endl;
    std::cout << variable << std::endl;

    s_print();
    print();

    return 0;
}