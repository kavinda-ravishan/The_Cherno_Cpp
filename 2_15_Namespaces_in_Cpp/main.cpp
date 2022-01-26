#include <iostream>
#include <string>
namespace Reverse
{
    void print(const char *text)
    {
        char *temp = (char *)malloc(sizeof(char) * strlen(text));
        strcpy(temp, text);
        std::reverse(temp, (temp + strlen(temp)));
        std::cout << temp << std::endl;
        free(temp);
    }
} // namespace revers
namespace Normal
{
    namespace Text
    {

        void print(const char *text)
        {
            std::cout << text << std::endl;
        }
    }
} // namespace Normal

int main()
{
    const char *name = "kavinda";

    {
        Reverse::print(name);
        Normal::Text::print(name);
    }
    {
        using Normal::Text::print;
        print(name);
    }
    {
        namespace txt = Normal::Text;
        txt::print(name);
    }
    {
        using namespace Normal;
        using namespace Text;
        print(name);
    }

    return 0;
}