#include <iostream>

class Entity
{
private:
    int X{0}, Y{0};

protected:
    const char *m_Name;

public:
    friend std::ostream &operator<<(std::ostream &ostr, const Entity &e);
};

std::ostream &operator<<(std::ostream &ostr, const Entity &e)
{
    return (ostr << e.X << ", " << e.Y);
}

class Player : public Entity
{
public:
    Player(const char *name)
    {
        m_Name = name;
    }
};

int main()
{
    Player p("kavinda");
    std::cout << p << std::endl;

    return 0;
}