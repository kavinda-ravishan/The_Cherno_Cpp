#include <iostream>
#include <string>
#include <array>
#include <tuple>
#include <utility>

void withRef(std::string &string1, std::string &string2)
{
    string1 = "kavinda";
    string2 = "ravishan";
}

void printRef()
{
    std::string firstName;
    std::string lastName;

    withRef(firstName, lastName);

    std::cout << firstName << " " << lastName << std::endl;
}

std::string *withArray()
{
    return new std::string[]{"kavinda", "ravishan"};
}

void printArray()
{
    std::string *name = withArray();

    std::cout << name[0] << " " << name[1] << std::endl;
}

std::array<std::string, 2> withStdArray()
{
    std::array<std::string, 2> name = {"kavinda", "ravishan"};
    return name;
}

void printStdArray()
{
    std::array<std::string, 2> name = withStdArray();

    std::cout << name[0] << " " << name[1] << std::endl;
}

std::tuple<std::string, std::string> withTuple()
{
    return std::make_pair<std::string, std::string>("kavinda", "ravishan");
}

void printTuple()
{
    std::tuple<std::string, std::string> name = withTuple();
    std::cout << std::get<0>(name) << " " << std::get<1>(name) << std::endl;
}

std::pair<std::string, std::string> withPair()
{
    return std::pair<std::string, std::string>("kavinda", "ravishan");
}

void printPair()
{
    std::pair<std::string, std::string> name = withPair();
    std::cout << name.first << " " << name.second << std::endl;
}

struct Name
{
    std::string firstName, lastName;
};

Name withStruct()
{
    return {"kavinda", "ravishan"};
}

void printStruct()
{
    Name name = withStruct();

    std::cout << name.firstName << " " << name.lastName << std::endl;
}

int main()
{
    printRef();
    printArray();
    printStdArray();
    printTuple();
    printPair();
    printStruct();

    return 0;
}