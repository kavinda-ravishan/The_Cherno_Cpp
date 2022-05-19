#include <iostream>

void example_1()
{
    int x = 2;
    double y = (int)x;
    std::cout << y << std::endl;

    int a = 3;
    double b = static_cast<double>(a);
    std::cout << b << std::endl;

    int c = 5;
    // Type Punning
    float &d = *reinterpret_cast<float *>(&c);
    std::cout << d << std::endl;
}

class Base
{
public:
    Base() {}
    virtual ~Base() {}
};

class Derived_1 : public Base
{
};

class Derived_2 : public Base
{
};

void example_2()
{
    Derived_1 *d1_ptr = new Derived_1();

    Base *base = d1_ptr;

    Derived_2 *d2_ptr = dynamic_cast<Derived_2 *>(base);

    std::cout << d2_ptr << std::endl;
    std::cout << (d2_ptr ? "Derived_2" : "Derived_1") << std::endl;
}

int main()
{
    const int *const x = new int(123);
    int *y = const_cast<int *>(x);
    *y = 321;

    std::cout << x << ", " << y << std::endl;
    std::cout << *x << ", " << *y << std::endl;

    y = nullptr;

    delete x;
    return 0;
}