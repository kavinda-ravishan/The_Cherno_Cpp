#include <iostream>

static const char *s_Variable = "s_Variable in Utility";
const char *variable = "Global variable";

static void s_print()
{
    std::cout << "S_Print in Utility\n";
}

void print()
{
    std::cout << "Global function\n";
}