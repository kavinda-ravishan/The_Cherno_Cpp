#include <iostream>

static int s_Level = 5;
static int s_Speed = 0;

int main()
{
    s_Speed = s_Level < 10 ? 10 : 20;

    std::cout << s_Speed << std::endl;

    unsigned int level = 7;
    char txt = (level == 0) ? '0' : (level == 1) ? '1'
                                                 : '9';

    std::cout << txt << std::endl;

    bool b = true;
    std::cout << (b ? "true" : "false") << std::endl;

    return 0;
}