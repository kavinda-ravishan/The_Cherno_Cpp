#include <iostream>
#include <chrono>
#include <array>

class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;

    void Stop()
    {
        auto entTimePoint = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(entTimePoint).time_since_epoch().count();

        auto duration = end - start;
        double ms = duration * 0.001;

        std::cout<< duration << " us ( "<<ms<<" ms )\n";
    }
public:
    Timer()
    {
        m_StartTimePoint = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        Stop();
    }
};

void test_1()
{
    int value = 0;
    {
        Timer t;
        for(int i=0; i<1000000; i++)
        {
            value+=2;
        }
    }
    std::cout<<value<<std::endl;
}

int main()
{
    struct Vec2
    {
        float x, y;
    };
    

    std::cout<<"Make shared.\n";
    {
        std::array<std::shared_ptr<Vec2>, 1000> ptrs;
        Timer t;
        for(int i=0; i< ptrs.size(); i++)
        {
            ptrs[i] = std::make_shared<Vec2>();
        }
    }

    std::cout<<"New shared.\n";
    {
        std::array<std::shared_ptr<Vec2>, 1000> ptrs;
        Timer t;
        for(int i=0; i< ptrs.size(); i++)
        {
            ptrs[i] = std::shared_ptr<Vec2>(new Vec2());
        }
    }

    std::cout<<"Make unique.\n";
    {
        std::array<std::unique_ptr<Vec2>, 1000> ptrs;
        Timer t;
        for(int i=0; i< ptrs.size(); i++)
        {
            ptrs[i] = std::make_unique<Vec2>();
        }
    }

    return 0;
}