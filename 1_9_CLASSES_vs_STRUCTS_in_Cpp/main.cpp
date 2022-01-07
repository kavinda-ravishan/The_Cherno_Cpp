#include <iostream>

#define LOG(x) std::cout << x << std::endl

class A
{
    int x;
};

struct B
{
    int x;

    B(int x) : x(x) {}

    B operator-(B a)
    {
        return this->x - a.x;
    }
};

union C
{
    int x, y;
    C(int x) : x(x) {}
    C operator+(C a)
    {
        return this->x + a.x;
    }
};

B operator+(B a, B b)
{
    return a.x + b.x;
}

int main()
{
    LOG(sizeof(A));
    LOG(sizeof(B));
    LOG(sizeof(C));

    B a(12);
    B b(4);
    LOG((a + b).x);
    LOG((a - b).x);

    C c1 = 2;
    C c2 = 5;

    LOG((c1 + c2).x);
    LOG((c1 + c2).y);

    return 0;
}