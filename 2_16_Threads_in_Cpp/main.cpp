#include <iostream>
#include <thread>

static bool s_Finished = false;

void doWork()
{
    std::cout << "New Thread Id" << std::this_thread::get_id() << std::endl;

    while (!s_Finished)
    {
        using namespace std::literals::chrono_literals;

        std::cout << "Working...\n";
        std::this_thread::sleep_for(1s);
    }
}

int main()
{
    std::cout << "Main Thread Id" << std::this_thread::get_id() << std::endl;

    std::thread worker(doWork);
    std::cin.get();

    s_Finished = true;
    worker.join();

    std::cout << "Finished\n";

    return 0;
}