#include <iostream>
#include <memory>

class Entity
{
public:
    Entity()
    {
        std::cout << "Entity created\n";
    }
    ~Entity()
    {
        std::cout << "Entity deleted\n";
    }

    void print_name()
    {
        std::cout << "Entity\n";
    }
};

int main()
{
    {
        // cannot copy unique pointer or assign it to other
        std::unique_ptr<Entity> eptr = std::make_unique<Entity>();
        eptr->print_name();
    }

    {
        std::shared_ptr<Entity> eptr_cpy;
        {
            // object delete when ref count hit zero
            std::shared_ptr<Entity> eptr = std::make_shared<Entity>();
            eptr_cpy = eptr;
        }
        eptr_cpy->print_name();
    }

    {
        std::weak_ptr<Entity> eptr_cpy;
        {
            // object delete when ref count hit zero
            std::shared_ptr<Entity> eptr = std::make_shared<Entity>();
            // ref count not going to increase in shared_ptr
            eptr_cpy = eptr;
            std::cout << eptr_cpy.expired() << std::endl;
        }
        std::cout << eptr_cpy.expired() << std::endl;
    }

    return 0;
}