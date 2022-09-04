// Small String Optimization(SSO) : If string smaller than 15 characters VS-STL use stack buffer
// Bigger than 16 characters use heap allocation.
#include <string>

void* operator new(size_t size)
{
    printf("Allocated : %u\n", size);
    return malloc(size);
}

int main()
{
    std::string name1 = "kavinda"; // (<= 15)
    std::string name2 = "kavinda12345678901234567890"; // Allocated : 32 (<= 16)

    return 0;
}