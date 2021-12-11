#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    unsigned int var1 = 0xFFFFFFFF; // 4294967295
    int var2(9);
    cout << var1 << endl;
    cout << var2 << endl;

    int var3 = ((4294967295UL - 1) / 2) + 1;
    int var4 = -2147483648 - 1;

    cout << var3 << endl;
    cout << var4 << endl;

    cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(long long) << endl;

    float var5 = 1.2f;
    double var6 = 23.4;

    cout << var5 << endl;
    cout << var6 << endl;

    return 0;
}