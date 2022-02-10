#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;

public:
    Entity() : m_Name("Unknown") {}
    Entity(const std::string &name) : m_Name(name) {}

    const std::string &GetName() const
    {
        return m_Name;
    }
};

int main()
{
    Entity e1;
    std::cout << e1.GetName() << std::endl;

    Entity e2("111111");
    std::cout << e2.GetName() << std::endl;

    Entity e3 = "222222";
    std::cout << e3.GetName() << std::endl;

    Entity e4 = Entity("333333");
    std::cout << e4.GetName() << std::endl;

    Entity *eptr1 = new Entity();
    std::cout << eptr1->GetName() << std::endl;
    delete eptr1;

    Entity *eptr2 = new Entity("444444");
    std::cout << eptr2->GetName() << std::endl;
    delete eptr2;

    return 0;
}