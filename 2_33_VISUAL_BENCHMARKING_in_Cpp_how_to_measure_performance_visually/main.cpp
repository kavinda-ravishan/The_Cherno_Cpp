#include <iostream>
#include <string>
#include <chrono>
#include <cmath>
#include <thread>
#include "Instrumentor.h"

#define PROFILING 1
#if PROFILING
#define PROFILE_SCOPE(name) InstrumentationTimer timer##__LINE__(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCSIG__)
#else
#define PROFILE_SCOPE(name)
#define PROFILE_FUNCTION()
#endif

void function1()
{
    PROFILE_FUNCTION();
    for(int i=0;i<1000;i++)
    {
        std::cout<<"#"<<i<<std::endl;
    }
}

void function2()
{
    PROFILE_FUNCTION();
    for(int i=0;i<1000;i++)
    {
        std::cout<<"#"<<sqrt(i)<<std::endl;
    }
}


void RunBenchMarks()
{
    PROFILE_FUNCTION();
    std::thread t(function1);
    function2();
 
    t.join();
}

int main()
{
    Instrumentor::Get().BeginSession("profile");
    RunBenchMarks();
    Instrumentor::Get().EndSession();

    return 0;
}