#include <iostream>

void example_1()
{
    struct Union
    {
        union
        {
            float a;
            int b;
        };
    };

    Union u;
    u.a = 2.0f;

    std::cout << u.a << ", " << u.b << std::endl;
}

struct Vector2
{
    float x, y;
};

struct Vector4
{
    union
    {
        struct
        {
            float x, y, z, w;
        };
        struct
        {
            Vector2 a, b;
        };
    };
};

std::ostream &operator<<(std::ostream &ostr, const Vector2 &vector)
{
    return ostr << vector.x << ", " << vector.y;
}

int main()
{
    Vector4 vec = {1.0f, 2.0f, 3.0f, 4.0f};
    std::cout << vec.a << std::endl;
    std::cout << vec.b << std::endl;
    vec.z = 500.0f;
    std::cout << vec.a << std::endl;
    std::cout << vec.b << std::endl;

    return 0;
}