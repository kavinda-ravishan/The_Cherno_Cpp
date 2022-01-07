#include <iostream>
#include <vector>
#include <unordered_map>
#define LOG(x) std::cout << x << std::endl

auto get_int(int x)
{
    return x;
}

std::pair<std::string, int> info()
{
    return {"kavinda", 25};
}

class Device
{
};
class DeviceManager
{
private:
    std::unordered_map<std::string, std::vector<Device *>> m_Devices;

public:
    using DeviceMap = std::unordered_map<std::string, std::vector<Device *>>;
    // or
    typedef std::unordered_map<std::string, std::vector<Device *>> DeviceMap;

    const std::unordered_map<std::string, std::vector<Device *>> &GetDevices() const
    {
        return m_Devices;
    }
};

int main()
{
    auto text = "hello";
    LOG(text);

    auto x1 = 123;
    auto x2 = 123u; // unsigned int

    auto f1 = 0.12;  // double
    auto f2 = 0.23f; // float

    auto l1 = 123l;   // long
    auto l2 = 123ll;  // long long
    auto l3 = 123ull; // unsigned long long

    auto x = get_int(12);
    LOG(x);

    auto ptr = &x; // int*

    auto data = info();
    LOG(data.first);
    LOG(data.second);

    std::vector<std::string> name = {"kavinda", "ravishan"};

    for (std::vector<std::string>::iterator it = name.begin(); it != name.end(); it++)
    {
        LOG(*it);
    }

    for (auto it = name.begin(); it != name.end(); it++)
    {
        LOG(*it);
    }

    DeviceManager dm;
    const DeviceManager::DeviceMap &devices = dm.GetDevices();

    const auto &devicesAuto = dm.GetDevices();

    return 0;
}