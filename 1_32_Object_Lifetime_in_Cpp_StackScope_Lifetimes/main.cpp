#include <iostream>

class Entity
{
public:
    Entity()
    {
        std::cout << "Entity created\n";
    }
    ~Entity()
    {
        std::cout << "Entity deleted\n";
    }
};

template <class T>
class ScopedPtr
{
private:
    T *m_Ptr;

public:
    ScopedPtr(T *ptr) : m_Ptr(ptr) {}
    ~ScopedPtr()
    {
        delete m_Ptr;
    }
};

int main()
{
    std::cout << "start\n";
    // Entity *eptr;

    std::cout << "start of scope\n";
    {
        // Entity e;
        ScopedPtr<Entity> sptr = new Entity();
        // eptr = new Entity();
    }
    std::cout << "end of scope\n";

    // delete eptr;

    std::cout << "end\n";

    return 0;
}