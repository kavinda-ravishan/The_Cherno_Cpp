#include <iostream>

class String
{
private:
    char *m_Buffer;
    unsigned int m_Size;

public:
    String(const char *string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1]; // +1 for null char
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0; // adding null termination char
    }

    String(const String &other) // copy constructor
        : m_Size(other.m_Size)
    {
        std::cout << "Copied" << std::endl;
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }

    ~String()
    {
        delete[] m_Buffer;
    }

    char &operator[](unsigned int index)
    {
        return m_Buffer[index];
    }

    friend std::ostream &operator<<(std::ostream &stream, const String &string); // friend function (now function can access class private members)
};

std::ostream &operator<<(std::ostream &stream, const String &string)
{
    stream << string.m_Buffer; // m_Buffer private member can access (friend function)
    return stream;
}

void printString(String string)
{
    std::cout << string << std::endl;
}

void printStringR(const String &string)
{
    std::cout << string << std::endl;
}

int main(int argc, char *argv[])
{
    String name = "kavinda";
    String name2 = name;

    name[1] = 'e';

    std::cout << name << std::endl;
    std::cout << name2 << std::endl;

    printString(name);
    printStringR(name);
    printStringR("name");

    return 0;
}