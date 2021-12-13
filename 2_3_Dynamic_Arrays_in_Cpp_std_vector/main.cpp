#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z;
};

std::ostream &operator<<(std::ostream &stream, const Vertex &vertex)
{
    return stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
}

std::ostream &operator<<(std::ostream &stream, const std::vector<Vertex> &vector)
{
    for (const Vertex &v : vector)
    {
        stream << v << std::endl;
    }
    return stream;
}

int main()
{
    Vertex v1 = {1, 2, 3};
    Vertex v2 = {4, 5, 6};

    std::vector<Vertex> vec = {v1, v2};
    vec.push_back({7, 8, 9});
    vec.push_back({10, 11, 12});

    std::cout << "Vec :\n"
              << vec << std::endl;

    vec.erase(vec.begin() + 1);
    std::cout << "Vec :\n"
              << vec << std::endl;

    vec.clear();
    std::cout << "Vec :\n"
              << vec << std::endl;

    return 0;
}