#include <iostream>
#include <string>

namespace text
{
    void print(const char *name)
    {
        std::cout << name << std::endl;
    }
}

namespace text
{
    void print(std::string name)
    {
        std::reverse(name.begin(), name.end());
        std::cout << name << std::endl;
    }
}

int main()
{
    const char *first_name = "kavinda";
    std::string last_name = "ravishan";

    text::print(first_name);
    text::print(last_name);

    using namespace text;
    print(first_name);
    print(last_name);

    namespace txt = text;
    txt::print(first_name);
    txt::print(last_name);

    return 0;
}