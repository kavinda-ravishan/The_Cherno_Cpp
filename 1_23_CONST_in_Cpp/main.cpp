#include <iostream>

class Entity
{
private:
    int m_X, m_Y;
    int *m_ptrX, *m_ptrY;
    mutable int m_mX;

public:
    int GetX() const // this method not going to modify class member variables
    {
        m_mX++;
        // m_X++;
        return m_X;
    }

    void SetX(int x)
    {
        m_X = x;
    }

    const int *const Get_ptr() const
    {
        return m_ptrX;
    }
};

void print_X(const Entity &e)
{
    std::cout << e.GetX() << std::endl;
}

int main()
{
    const int MAX_AGE = 90;
    // MAX_AGE = 100;

    int *ptr = new int(123);
    *ptr = 321;
    delete ptr;
    ptr = nullptr;

    const int *ptr1 = new int(123);
    //  or
    // int const *ptr1 = new int(123);
    //*ptr1 = 321;
    delete ptr1;
    ptr1 = nullptr;

    int *const ptr2 = new int(123);
    *ptr2 = 321;
    delete ptr2;
    // ptr2 = nullptr;

    const int *const ptr3 = new int(123);
    // *ptr3 = 321;
    delete ptr3;
    // ptr3 = nullptr;

    Entity e;
    e.SetX(124);
    print_X(e);

    return 0;
}