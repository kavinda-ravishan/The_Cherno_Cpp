#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    int m_Age;

public:
    Entity() : m_Name("Unknown"), m_Age(0) {}
    Entity(const std::string &name, int age) : m_Name(name), m_Age(age) {}
    const std::string &GetName() const
    {
        return m_Name;
    }
    const int &GetAge() const
    {
        return m_Age;
    }
};

int main()
{
    const Entity e0;
    std::cout << e0.GetName() << ", " << e0.GetAge() << std::endl;

    const Entity e1 = {"kavinda", 12};
    std::cout << e1.GetName() << ", " << e1.GetAge() << std::endl;

    return 0;
}