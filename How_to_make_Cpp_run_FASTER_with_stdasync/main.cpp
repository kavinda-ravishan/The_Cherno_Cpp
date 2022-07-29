#include <iostream>
#include <chrono>
#include <future>
#include <vector>

struct Timer
{
    std::chrono::time_point<std::chrono::steady_clock> start, end;
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

static std::mutex s_mutex;
void work(int id, std::vector<int>& vec)
{
    int val = 0;
    for(int i=0; i<=1000000; i++)
    {
        val = i;
    }
    std::lock_guard<std::mutex> lock(s_mutex);
    vec.push_back(val);
    std::cout<<"Work "<<id<<" done\n";
}

int main()
{
    {
        std::vector<int> vec;

        Timer* t = new Timer();
        for(int i=0; i<10; i++)
        {
            work(i, vec);
        }
        delete t;

        for(int& i:vec)
        {
            std::cout<<i<<" | ";
        }
        std::cout<<std::endl;
    }

    {
        std::vector<int> vec;
        // void work return type
        std::vector<std::future<void>> futures;

        Timer* t = new Timer();
        for(int i=0; i<10; i++)
        {
            futures.push_back(std::async(std::launch::async, work, i, std::ref<std::vector<int>>(vec)));
        }

        for(std::future<void>& f : futures)
        {
            f.wait();
        }
        delete t;

        for(int& i:vec)
        {
            std::cout<<i<<" | ";
        }
        std::cout<<std::endl;
    }

    return 0;
}