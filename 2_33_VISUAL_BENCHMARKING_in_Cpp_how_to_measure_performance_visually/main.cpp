#include <iostream>
#include <string>
#include <chrono>
#include <cmath>

class Timer
{
public:
    Timer(const char* name):m_Name(name), m_Stopped(false)
    {
        m_StartTimePoint = std::chrono::high_resolution_clock::now();
    }

    void Stop()
    {
        auto endTimePoint = std::chrono::high_resolution_clock::now();

        long long start = std::chrono::time_point_cast<std::chrono::milliseconds>(m_StartTimePoint).time_since_epoch().count();
        long long end = std::chrono::time_point_cast<std::chrono::milliseconds>(endTimePoint).time_since_epoch().count();

        std::cout<< m_Name << ": "<<(end-start)<<"ms\n";
        m_Stopped = true;
    }

    ~Timer()
    {
        if(!m_Stopped)
        {
            Stop();
        }
    }

private:
    const char* m_Name;
    bool m_Stopped;
    std::chrono::time_point<std::chrono::steady_clock> m_StartTimePoint;
};

void function1()
{
    for(int i=0;i<1000;i++)
    {
        std::cout<<"#"<<i<<std::endl;
    }
}

void function2()
{
    for(int i=0;i<1000;i++)
    {
        std::cout<<"#"<<sqrt(i)<<std::endl;
    }
}


int main()
{
    function1();
    function2();

    return 0;
}