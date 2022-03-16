#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

std::ostream &operator<<(std::ostream &ostr, std::vector<int> vec)
{
    for (int i : vec)
    {
        ostr << i << " | ";
    }
    ostr << std::endl;
    return ostr;
}

int main()
{
    std::vector<int> vec = {5, 3, 7, 1, 4};
    std::cout << vec << std::endl;

    std::sort(vec.begin(), vec.end());
    std::cout << vec << std::endl;

    std::sort(vec.begin(), vec.end(), std::greater<int>());
    std::cout << vec << std::endl;

    std::sort(vec.begin(), vec.end(), [](int a, int b)
              { return a < b; });
    std::cout << vec << std::endl;

    std::sort(vec.begin(), vec.end(), [](int a, int b)
              { 
                  if (a == 1)
                  {
                      return false;
                  }
                  if (b == 1)
                  {
                      return true;
                  }
                  return a < b; });
    std::cout << vec << std::endl;

    return 0;
}