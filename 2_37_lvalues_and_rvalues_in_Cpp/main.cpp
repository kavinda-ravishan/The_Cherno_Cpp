#include <iostream>
#include <string>

int GetValue()
{
    return 10;
}

int& GetLValue()
{
    static int val;
    return val;
}

void print_value(int& x)
{
    std::cout<<"lvalue : "<<x<<std::endl;
}

// && : rvalue reference
void print_value(int&& x)
{
    std::cout<<"rvalue : "<<x<<std::endl;
}

void print_const_lvalue_ref(const int& x)
{
    std::cout<<"const lvalue ref : "<<x<<std::endl;
}

void print_string(std::string& str)
{
    std::cout<<"lvalue : "<<str<<std::endl;
}

void print_string(std::string&& str)
{
    std::cout<<"rvalue : "<<str<<std::endl;
}

void print_string_i_and_r_value(const std::string& str)
{
    std::cout<<"rvalue : "<<str<<std::endl;
}

int main()
{
    // i is lvalue (this have storage) = 10 is rvalue
    int i = 10;

    // for rvalues assignment operation (10 = i) not allowed

    // j is lvalue (this have storage) = GetValue (GetValue is 10) is rvalue
    int j = GetValue();

    // GetLValue is lvalue (this have storage) = 123 is rvalue
    GetLValue() = 123;
    std::cout<<GetLValue()<<std::endl;

    // call lvalue function
    print_value(i);

    // call rvalue function
    print_value(21);

    print_const_lvalue_ref(i);
    print_const_lvalue_ref(123);

    //          lvalue        rvalue
    std::string first_name = "hello";
    std::string last_name = "world";

    //          lvalue      rvalue (create temp object)
    std::string full_name = first_name + last_name;

    // ivalue
    print_string(first_name);
    // rvalue
    print_string(first_name + last_name);

    // ivalue
    print_string_i_and_r_value(first_name);
    // rvalue
    print_string_i_and_r_value(first_name + last_name);

    return 0;
}