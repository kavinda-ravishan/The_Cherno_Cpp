#include <iostream>

#define Log(x) std::cout << x << std::endl

class Entity
{
public:
    float x, y;

    Entity()
    {
        x = 0.0f;
        y = 0.0f;
    }

    Entity(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    void print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

class NoConstructor
{
public:
    NoConstructor() = delete;
    static void Write()
    {
        Log("No Constructor");
    }
};

int main()
{
    Entity e;
    e.print();

    Entity e1(0.0f, 0.0f);
    e1.print();

    Entity *ePtr = new Entity(0, 0);
    ePtr->print();
    delete ePtr;

    NoConstructor::Write();

    return 0;
}