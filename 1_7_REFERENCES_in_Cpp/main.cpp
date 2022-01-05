#include <iostream>

#define Log(x) std::cout << x << std::endl

template <typename T>
void print_ref(T &var)
{
    Log(&var);
}

template <typename T>
void print_var(T var)
{
    Log(&var);
}

int &get_int()
{
    int &x = *(new int(123));
    Log(&x);
    Log(x);
    return x;
}

int main()
{
    int x = 123;

    Log(&x);

    print_ref(x);
    print_var(x);

    int &ref = x;

    Log(x);
    Log(&x);

    int &val = get_int();
    Log(&val);
    Log(val);

    return 0;
}