#include <iostream>
#include <variant>

int main()
{
    std::variant<std::string, int> data;

    data = "kavinda";
    std::cout<< std::get<std::string>(data)<<std::endl;

    // find the type : 0 - string, 1 - int
    std::cout<<data.index()<<std::endl;

    data = 27;
    std::cout<< std::get<int>(data)<<std::endl;

    // find the type : 0 - string, 1 - int
    std::cout<<data.index()<<std::endl;

    std::cout<<std::get_if<std::string>(&data)<<std::endl;
    std::cout<<std::get_if<int>(&data)<<std::endl;

    int age = 0;
    if(auto value = std::get_if<int>(&data))
    {
         age = *value;
    }


    return 0;
}