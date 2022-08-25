#include <string>
#include <iostream>

// static uint32_t s_AllocCount = 0;
// void *operator new (size_t size)
// {
//     s_AllocCount++;
//     printf("Allocating : %i\n", size);
//     return malloc (size);
// }

void print_str(const std::string& name)
{
    std::cout<< name <<std::endl;
}

void print_str_view(std::string_view name)
{
    std::cout<< name <<std::endl;
}

int main()
{
    //std::string name = "kavinda ravishan"; // alloc here
    //std::string first = name.substr(0, 7); // alloc here
    //std::string last = name.substr(8, 15); // alloc here

    //print_str(name);
    //print_str(first);
    //print_str(last);

    // std::string_view first(name.c_str(), 7); // from string
    // std::string_view last(name.c_str() + 8, 8); // from string

    const char* name = "kavinda ravishan";
    std::string_view first(name, 7);
    std::string_view last(name + 8, 8);

    print_str(name);
    print_str_view(first);
    print_str_view(last);

    //std::cout<<"Aloc count : " <<s_AllocCount<<std::endl;

    return 0;
}