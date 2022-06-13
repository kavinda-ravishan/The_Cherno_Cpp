#include <iostream>
#include <string>

class Entity
{
public:
    virtual ~Entity(){}
};

class Player: public Entity
{
};

class Enemy: public Entity
{
};

int main()
{
    // RTTI : run time type information

    Player* player = new Player();
    Entity* entity = player;
    Enemy* enemy = new Enemy();

    Enemy* enemy1 = dynamic_cast<Enemy*>(entity);
    std::cout<< (enemy1 ? "Enemy" : "Player") << std::endl; 

    Enemy* enemy2 = dynamic_cast<Enemy*>(enemy);
    std::cout<< (enemy2 ? "Enemy" : "Player") << std::endl; 

    return 0;
}