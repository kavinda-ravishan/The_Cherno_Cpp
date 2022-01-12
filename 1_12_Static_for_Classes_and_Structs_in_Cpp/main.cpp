#include <iostream>

struct Entity
{
    static int x, y;
    int z;

    void print()
    {
        std::cout << x << ", " << y << ", " << z << std::endl;
    }

    static void print_s()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

int Entity::x;
int Entity::y;

int main()
{
    Entity e1;
    e1.x = 2;
    e1.y = 3;
    e1.z = 4;

    Entity e2;
    e2.x = 5;
    e2.y = 8;
    e2.z = 9;

    e1.print(); // 5, 8
    e2.print(); // 5, 8

    Entity::x = 12;
    Entity::y = 13;

    Entity::print_s();

    return 0;
}