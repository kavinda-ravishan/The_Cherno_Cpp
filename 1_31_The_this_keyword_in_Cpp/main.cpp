#include <iostream>

class Entity
{
private:
    int x, y;

public:
    Entity(int x, int y)
    {
        Entity *const e = this;
        e->x = x;
        e->y = y;

        // this->x = x;
        // this->y = y;
    }

    int GetX() const
    {
        const Entity *const e = this;
        return e->x;
        // return x;
    }

    friend std::ostream &operator<<(std::ostream &, const Entity &);
};

std::ostream &operator<<(std::ostream &ostr, const Entity &e)
{
    return ostr << e.x << ", " << e.y;
}

int main()
{
    Entity e(12, 56);

    std::cout << e << std::endl;
    std::cout << e.GetX() << std::endl;

    return 0;
}