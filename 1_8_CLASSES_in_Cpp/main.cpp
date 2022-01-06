#include <iostream>

#define Log(x) std::cout << x << std::endl

class Player
{
public:
    int x, y;
    int speed;

    Player() : x(0), y(0), speed(1) {}

    void Move(int xa, int ya)
    {
        x += xa * speed;
        y += ya * speed;
    }
};

int main()
{
    Player player;
    player.Move(1, 1);

    Log(player.x);
    Log(player.y);

    return 0;
}