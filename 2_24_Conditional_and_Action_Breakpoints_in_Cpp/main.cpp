#include <thread>
#include <iostream>

static bool run = true;

void get_user_input()
{
    int i = 0;
    std::cin >> i;
    if (i)
    {
        run = false;
    }
}

int main()
{
    int i = 0;
    int j = 0;
    std::thread t(get_user_input);
    while (run)
    {
        i++;
        j += 2;
        std::cout << "i : " << i << ", j : " << j << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "Done\n";
    t.join();

    return 0;
}