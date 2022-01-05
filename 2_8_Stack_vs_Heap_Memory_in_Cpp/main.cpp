#include <iostream>

#define Log(x) std::cout << x << std::endl

struct Vector3
{
    int x, y, z;
};

std::ostream &operator<<(std::ostream &ostr, const Vector3 &vec)
{
    return ostr << vec.x << ", " << vec.y << ", " << vec.z;
}

int main()
{
    int s_value = 123;
    int &h_value = *(new int(123));

    Log(s_value);
    Log(h_value);

    int s_array[] = {1, 2, 3, 4, 5};
    int *h_array = new int[5]{1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        Log(s_array[i]);
        Log(h_array[i]);
    }

    Vector3 s_vec = {1, 2, 3};
    Vector3 *h_vec = new Vector3({1, 2, 3});

    Log(s_vec);
    Log(*h_vec);

    delete &h_value;
    delete[] h_array;
    delete h_vec;

    return 0;
}