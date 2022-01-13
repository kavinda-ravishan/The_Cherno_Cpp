#include <iostream>

enum State : unsigned char
{
    A = 0,
    B,
    C
};

int main()
{
    State s = State::B;

    switch (s)
    {
    case State::A:
        std::cout << "A\n";
        break;
    case State::B:
        std::cout << "B\n";
        break;
    case State::C:
        std::cout << "C\n";
        break;
    default:
        break;
    }

    return 0;
}