#include <iostream>

class Entity
{
public:
    void print() const
    {
        std::cout << "Entity class\n";
    }
};

class ScopedPtr
{
private:
    Entity *m_Obj;

public:
    ScopedPtr(Entity *entity) : m_Obj(entity) {}
    ~ScopedPtr()
    {
        delete this->m_Obj;
    }
    Entity *getObject1()
    {
        return m_Obj;
    }
    Entity &getObject2()
    {
        return *m_Obj;
    }

    Entity *operator->()
    {
        return m_Obj;
    }

    const Entity *operator->() const
    {
        return m_Obj;
    }
};

struct Vector3
{
    float x, y, z;
};

void Part_1()
{
    Entity e;
    e.print();

    Entity *ePtr = &e;
    ePtr->print();
    (*ePtr).print();

    Entity &entity = *ePtr;
    entity.print();
}

void Part_2()
{
    ScopedPtr entity1 = new Entity();

    entity1.getObject1()->print();
    entity1.getObject2().print();

    entity1->print();

    const ScopedPtr entity2 = new Entity();
    entity2->print();
}

void Part_3()
{
    int x_offset = (int)&((Vector3 *)nullptr)->x;
    int y_offset = (int)&((Vector3 *)nullptr)->y;
    int z_offset = (int)&((Vector3 *)nullptr)->z;

    std::cout << x_offset << ", " << y_offset << ", " << z_offset << std::endl;
}

int main()
{
    Part_1();
    Part_2();
    Part_3();

    return 0;
}