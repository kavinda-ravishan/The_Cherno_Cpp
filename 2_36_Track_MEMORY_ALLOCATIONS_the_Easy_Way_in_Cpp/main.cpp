#include <cstdlib>
#include <cstdio>
#include <memory>

struct AllocationMetrics
{
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;

    uint32_t CurrentUsage(){return TotalAllocated - TotalFreed;}

};

static AllocationMetrics s_allocationMetrics; 

void* operator new(size_t size)
{
    printf("Memory allocated : %u\n", size);
    s_allocationMetrics.TotalAllocated += size;
    return malloc(size);
}

void operator delete(void* memory, size_t size)
{
    printf("Memory freeing : %u\n", size);
    s_allocationMetrics.TotalAllocated -= size;
    free(memory);
}

struct Object
{
    int x, y, z;
};


int main()
{
    {
        printf("Current Usage : %u bytes\n", s_allocationMetrics.CurrentUsage());
        std::unique_ptr<Object> obj = std::make_unique<Object>();
        printf("Current Usage : %u bytes\n", s_allocationMetrics.CurrentUsage());
    }

    printf("Current Usage : %u bytes\n", s_allocationMetrics.CurrentUsage());
    
    return 0;
}