#include <iostream>
#include <any>

int main()
{
    std::any data;

    data = 2;
    std::cout<<std::any_cast<int>(data)<<std::endl;

    data = "kavinda";
    std::cout<<std::any_cast<const char*>(data)<<std::endl;

    return 0;
}