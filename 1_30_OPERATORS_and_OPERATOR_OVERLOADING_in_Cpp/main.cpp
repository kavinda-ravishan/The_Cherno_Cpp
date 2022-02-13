#include <iostream>

struct Complex
{
    long double r, i;

    Complex(long double r) : r(r), i(0) {}
    Complex(long double r, long double i) : r(r), i(i) {}

    Complex operator+(const Complex &c) const
    {
        return Complex((this->r + c.r), (this->i + c.i));
    }
    Complex operator-(const Complex &c) const
    {
        return Complex((this->r - c.r), (this->i - c.i));
    }
    Complex &operator+()
    {
        return (*this);
    }

    Complex &operator-()
    {
        this->r = -(this->r);
        this->i = -(this->i);
        return (*this);
    }

    bool operator==(const Complex &c) const
    {
        return (this->r == c.r && this->i == c.i);
    }

    bool operator!=(const Complex &c) const
    {
        return !(*this == c);
    }
};

Complex operator"" _i(long double i)
{
    return {0.0L, i};
}

Complex operator"" _r(long double r)
{
    return {r, 0.0L};
}

std::ostream &operator<<(std::ostream &ostr, Complex c)
{
    return ostr << c.r << (c.i >= 0 ? "+" : "") << c.i << "i";
}

int main()
{
    Complex c1 = {1.0L, 2.02L};
    Complex c2 = {4.1L, -9.0L};

    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;

    Complex c3 = c1 + c2;
    std::cout << c3 << std::endl;

    Complex c4 = +1.0_r + -2.0_i;
    std::cout << c4 << std::endl;

    Complex c5 = -5.0_r + +2.0_i;
    std::cout << c5.operator+(1.0L) << std::endl;

    std::cout << ((c1 == c2) ? "True" : "False") << std::endl;
    std::cout << ((c1 == c1) ? "True" : "False") << std::endl;

    std::cout << ((c1 != c2) ? "True" : "False") << std::endl;
    std::cout << ((c1 != c1) ? "True" : "False") << std::endl;

    return 0;
}