#include <iostream>

#define Log(x) std::cout << x << std::endl

int main()
{
    int *ptr1 = new int(123);
    Log(*ptr1);

    int *arrPtr = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    for (int i = 0; i < 10; i++)
    {
        Log(arrPtr[i]);
    }
    delete[] arrPtr;

    int *ptr2 = (int *)malloc(sizeof(int));
    *ptr2 = 1234;
    Log(*ptr2);
    free(ptr2);

    void *ptr = malloc(sizeof(int));
    int *iptr = new (ptr) int(4321);

    Log(*iptr);
    Log(ptr);
    Log(iptr);

    return 0;
}
