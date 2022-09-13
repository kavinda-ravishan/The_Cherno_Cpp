#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z;

    Vertex(float x, float y, float z) : x(x), y(y), z(z) {}

    Vertex(const Vertex &vertex) : x(vertex.x), y(vertex.y), z(vertex.z)
    {
        std::cout << "Copied!\n";
    }
};

int main()
{
    std::cout << "Not Optimized\n";
    std::vector<Vertex> vec1;

    vec1.push_back(Vertex(1, 2, 3));
    vec1.push_back(Vertex(4, 5, 6));
    vec1.push_back(Vertex(7, 8, 9));
    std::cout << "\n";

    std::cout << "Optimized\n";
    std::vector<Vertex> vec2;
    vec2.reserve(3);

    vec2.emplace_back(1, 2, 3);
    vec2.emplace_back(4, 5, 6);
    vec2.emplace_back(7, 8, 9);

    return 0;
}
