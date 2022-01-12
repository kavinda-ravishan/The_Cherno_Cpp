#include <iostream>
#include <vector>

void hello()
{
    std::cout << "Hello\n";
}

void helloMe(const char *name)
{
    std::cout << "Hello " << name << std::endl;
}

template <typename T>
void printNum(const T &num)
{
    std::cout << num << std::endl;
}

template <typename T>
void IntegrateVector(const std::vector<T> &vec, void (*callback)(const T &))
{
    for (int num : vec)
    {
        callback(num);
    }
}

int main()
{
    auto fun1 = hello;
    fun1();

    void (*fun2)() = hello;
    fun2();

    void (*fun3)();
    fun3 = hello;
    fun3();

    typedef void (*funPtr)();
    funPtr fun4 = hello;
    fun4();

    typedef void (*helloMePtr)(const char *);
    helloMePtr fun5 = helloMe;
    fun5("kavinda");
    fun5("Ravishan");

    std::vector<int> vec = {1, 2, 54, 6, 7};
    IntegrateVector<int>(vec, printNum<int>);

    IntegrateVector<int>(vec, [](const int &num)
                         { std::cout << num << std::endl; });

    return 0;
}