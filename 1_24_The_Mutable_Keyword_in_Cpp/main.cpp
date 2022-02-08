#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    mutable int m_DebugCount = 0;

public:
    const std::string &GetName() const
    {
        m_DebugCount++;
        return m_Name;
    }

    void print_DebugCount() const
    {
        std::cout << m_DebugCount << std::endl;
    }

    void print_name_mem() const
    {
        std::cout << &m_Name << std::endl;
    }
};

int main()
{
    const Entity e;
    e.GetName();
    e.GetName();
    e.GetName();

    e.print_DebugCount();

    const std::string &name = e.GetName();
    std::cout << &name << std::endl;
    e.print_name_mem();

    int x = 123;
    auto fun = [=]() mutable // [=] : pass py value
    {
        x++; // create a new local variable x ( mutable need )
        std::cout << x << std::endl;
    };
    fun();
    std::cout << x << std::endl;

    return 0;
}