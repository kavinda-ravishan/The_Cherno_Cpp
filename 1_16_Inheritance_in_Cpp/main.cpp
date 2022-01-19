#include <iostream>

class Entity
{
public:
    float X{0}, Y{0}, Z{0};

    void move(float xa, float ya)
    {
        X += xa;
        Y += ya;
    }
};

class Player : public Entity
{
public:
    const char *Name;

    Player(const char *name) : Name(name) {}

    void printLocation()
    {
        std::cout << X << ", " << Y << std::endl;
    }

    void printName()
    {
        std::cout << Name << std::endl;
    }
};

int main()
{

    Player p("kavinda");
    p.printName();
    p.move(10, 5);
    p.printLocation();

    std::cout << sizeof(float) << std::endl;
    std::cout << sizeof(char *) << std::endl;
    std::cout << sizeof(Player) << std::endl;

    std::cout << (int)&(((Player *)nullptr)->X) << std::endl;
    std::cout << (int)&(((Player *)nullptr)->Y) << std::endl;
    std::cout << (int)&(((Player *)nullptr)->Z) << std::endl;
    std::cout << (int)&(((Player *)nullptr)->Name) << std::endl;

    return 0;
}