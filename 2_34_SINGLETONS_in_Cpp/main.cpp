#include <iostream>

class Singleton
{
public:
    Singleton(const Singleton&) = delete; // delete copy constructor
    static Singleton& Get() // get the instance
    {
        static Singleton instance;
        return instance;
    }

    static void print()
    {
        return Get().IPrint();
    }

private:
    Singleton(){}; // constructor is private
    void IPrint() {std::cout<<"Singleton\n";} // (printImple(implementation), printInternal)
};


int main()
{
    Singleton::print();

    Singleton& instance = Singleton::Get();
    instance.print();

    return 0;
}