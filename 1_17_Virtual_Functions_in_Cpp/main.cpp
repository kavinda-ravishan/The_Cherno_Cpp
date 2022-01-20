#include <iostream>

#define LOG(x) std::cout << x << std::endl

class Entity
{
public:
    virtual const char *GetName() { return "Entity"; }
};

class Player : public Entity
{
private:
    const char *m_Name;

public:
    Player(const char *name) : m_Name(name) {}
    const char *GetName() override { return m_Name; }
};

void printName(Entity *e)
{
    LOG(e->GetName());
}

int main()
{
    Entity *e = new Entity();
    LOG(e->GetName());

    Player *p = new Player("my player");
    LOG(p->GetName());

    Entity *e1 = new Entity();
    LOG(e1->GetName());

    Entity *e2 = new Player("my player");
    LOG(e2->GetName());

    printName(e1);
    printName(e2);

    return 0;
}