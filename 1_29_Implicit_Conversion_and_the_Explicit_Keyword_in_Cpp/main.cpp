#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    int m_Age;

public:
    Entity(const std::string &name) : m_Name(name), m_Age(-1) {}
    explicit Entity(int age) : m_Name("Unknown"), m_Age(age) {}

    const std::string &GetName() const
    {
        return m_Name;
    }

    const int &GetAge() const
    {
        return m_Age;
    }
};

void printEntity(const Entity &e)
{
    std::cout << e.GetName() << ", " << e.GetAge() << std::endl;
}

int main()
{
    Entity a = "kavinda";
    // Entity b = 25; // explicit constructor
    Entity b(25);

    printEntity(std::string("hello_1")); // const char* -> std::string -> Entity
    printEntity(Entity("hello_2"));
    // printEntity(123); // int -> Entity (error : explicit constructor)

    return 0;
}