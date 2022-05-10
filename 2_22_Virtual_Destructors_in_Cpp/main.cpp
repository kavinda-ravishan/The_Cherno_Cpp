#include <cstdio>

class Entity
{
public:
    Entity()
    {
        printf("Entity created.\n");
    }
    virtual ~Entity()
    {
        printf("Entity deleted.\n");
    }
};

class Player : public Entity
{
public:
    Player()
    {
        printf("Player created.\n");
    }
    ~Player()
    {
        printf("Player deleted.\n");
    }
};

int main()
{
    Entity *p = new Player();
    delete p;

    return 0;
}