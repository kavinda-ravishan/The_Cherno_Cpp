#include <iostream>
#include <stdlib.h>
#include <string>

// String Literals : "hello"
// always store in read only memory (actual binory)

int main()
{
    const char txt[] = "hello\n world\n";
    std::cout << strlen(txt) << std::endl;

    const char *text = "hello\n\0 world\n";
    std::cout << text; // print hello only
    std::cout << strlen(text) << std::endl;

    char edit[] = "this can edit!";
    std::cout << edit << std::endl;
    edit[13] = '.';
    std::cout << edit << std::endl;

    // wchar
    const char *name = u8"kavinda";
    const wchar_t *name1 = L"kavinda";
    const char16_t *name2 = u"kavinda";
    const char32_t *name3 = U"kavinda";

    std::cout << sizeof(char) << std::endl;
    std::cout << sizeof(wchar_t) << std::endl;
    std::cout << sizeof(char16_t) << std::endl;
    std::cout << sizeof(char32_t) << std::endl;

    std::string txt1 = (std::string) "hello " + "how are you.\n";

    using namespace std::string_literals;

    std::string txt2 = "hello "s + "how are you.\n";

    std::wstring txt3 = L"hello "s + L"how are you.\n";

    std::u32string txt4 = U"hello "s + U"how are you.\n";

    // para

    const char *para1 = "line1\n"
                        "line2\n"
                        "line3\n";

    const char *para2 = R"(line1
line2
line3)";

    std::cout << para1;
    std::cout << para2 << std::endl;

    return 0;
}