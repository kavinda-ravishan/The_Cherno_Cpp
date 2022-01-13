#include <iostream>
#include <vector>
#include <functional>

void ForEach(const std::vector<int> &vec, void (*callback)(int))
{
    for (int num : vec)
    {
        callback(num);
    }
}

int main()
{
    int var1 = 123;
    int var2 = 123;
    std::cout << &var1 << std::endl;
    std::cout << &var2 << std::endl;

    void (*fun1)() = []()
    {
        std::cout << "Cannot access var" << std::endl;
    };
    const std::function<void()> fun2 = [=]() mutable
    {
        var1 = 345; // mutable
        std::cout << &var1 << std::endl;
        std::cout << &var2 << std::endl;
    };
    const std::function<void()> fun3 = [&var1, var2]()
    {
        std::cout << &var1 << std::endl;
        std::cout << &var2 << std::endl;
    };
    const std::function<void()> &fun4 = [&]()
    {
        std::cout << &var1 << std::endl;
        std::cout << &var2 << std::endl;
    };

    fun1();
    fun2();
    fun3();
    fun4();

    std::vector<int> vec = {2, 4, 5, 6};

    auto lambda = [](int num)
    { std::cout << num << std::endl; };

    ForEach(vec, lambda);

    return 0;
}

// https://en.cppreference.com/w/cpp/language/lambda