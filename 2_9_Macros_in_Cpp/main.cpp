#include <iostream>
#include <string>

// #define DEGUB

// #ifdef DEGUB
// #define WAIT std::cin.get()
// #define LOG(x) std::cout << x << std::endl
// #else
// #define WAIT
// #define LOG(x)
// #endif

#define LOG(x) std::cout << x << std::endl

#define DEGUB 0
#define RELEASE

#if DEGUB == 1
#define NOTE std::cout << "DEBUG" << std::endl
#define WAIT std::cin.get()
#elif defined(RELEASE)
#define NOTE std::cout << "RELEASE" << std::endl
#define WAIT
#else
#define NOTE std::cout << "NO MODE" << std::endl
#define WAIT
#endif

#if 0
hello world
#endif

#define MAIN          \
    int main()        \
    {                 \
        LOG("Start"); \
        NOTE;         \
        WAIT;         \
                      \
        return 0;     \
    }

MAIN