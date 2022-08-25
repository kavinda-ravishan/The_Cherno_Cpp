#include <iostream>
#include <fstream>
#include <optional>

// need c++17
std::optional<std::string> ReadFileString(const std::string& path)
{
    std::ifstream stream(path);
    if(stream)
    {
        std::string result = "dummy data";
        // read file
        stream.close();
        return result;
    }

    return {};
}

void example_1()
{
    std::optional<std::string> data = ReadFileString("data3.txt");

    // if(data)
    if(data.has_value())
    {
        std::cout<<"File read successfully."<<std::endl;
        // std::cout<<*data<<std::endl;
        std::cout<<data.value()<<std::endl;
    }
    else
    {
        std::cout<<"File could not be opened."<<std::endl;
    }
}

int main()
{
    std::optional<std::string> data = ReadFileString("data.txt");
    std::string value = data.value_or("value for if file not present");

    // if(data)
    if(data.has_value())
    {
        std::cout<<"File read successfully."<<std::endl;
        std::cout<<value<<std::endl;
    }
    else
    {
        std::cout<<"File could not be opened."<<std::endl;
        std::cout<<value<<std::endl;
    }

    return 0;
}