#include <iostream>
#include <chrono>
#include <thread>

using namespace std::literals::chrono_literals;
// using Time = std::chrono::time_point<std::chrono::steady_clock>;
typedef std::chrono::time_point<std::chrono::steady_clock> Time;

struct Timer
{
    Time start, end;
    std::chrono::duration<float> duration;

    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;
        std::cout << ms << " ms\n";
    }
};

void Function()
{
    Timer t;
    for (int i = 0; i < 100; i++)
    {
        // std::cout << i << std::endl;
        std::cout << i << "\n";
    }
}

int main()
{
    Time start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(1s);
    Time end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start;

    std::cout << duration.count() << " s\n";

    // or

    Function();

    return 0;
}