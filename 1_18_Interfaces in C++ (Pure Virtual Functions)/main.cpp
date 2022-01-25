#include <iostream>

class Entity
{
public:
    virtual const char *GetName() = 0;
};

class Player : public Entity
{
private:
    const char *m_Name;

public:
    Player(const char *name) : m_Name(name) {}

    const char *GetName() override
    {
        return m_Name;
    }
};

void printName(Entity *e)
{
    std::cout << e->GetName() << std::endl;
}

int main()
{
    Player *p = new Player("Kavinda");

    printName(p);

    delete p;
    return 0;
}