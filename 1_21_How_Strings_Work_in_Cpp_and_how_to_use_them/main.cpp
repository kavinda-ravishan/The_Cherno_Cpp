#include <iostream>
#include <string>

void printString(const std::string &text)
{
    std::cout << text << std::endl;
}

int main()
{
    const char *c = "kavinda";
    std::cout << c << std::endl;
    std::cout << strlen(c) << std::endl;

    char name[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    std::cout << name << std::endl;

    std::string name2 = "kavinda";
    std::cout << name2 << std::endl;
    std::cout << name2.size() << std::endl;

    // std::string text = "hello" + (std::string) " kavinda";
    // or
    std::string text = (std::string) "hello" + " kavinda";
    text += " ravishan";
    std::cout << text << std::endl;

    if (text.find("kavinda") != std::string::npos)
        std::cout << "Yes\n";

    printString(name2);

    return 0;
}