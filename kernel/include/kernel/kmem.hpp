#ifndef KERNEL_KMEM_HPP
#define KERNEL_KMEM_HPP
#include <cstdint>
#include <cstddef>
namespace kernel
{
    template<typename T>
    class SharedPtr
    {
    
    };
    class PhysicalMemoryManager
    {
    public:
        virtual uintptr_t allocate_page() = 0;
        virtual void free_page(uintptr_t address) = 0;
        virtual size_t get_page_size() = 0;
        virtual size_t get_total_pages() = 0;
        virtual size_t get_free_pages() = 0;
        virtual size_t get_reserved_pages() = 0;
    };
    class VirtualMemoryManager
    {
    public:
        virtual void map(uintptr_t physical_address, uintptr_t virtual_address, size_t pages) = 0;
        virtual void unmap(uintptr_t virtual_address, size_t pages) = 0;
        virtual uintptr_t get_physical_address(uintptr_t virtual_address) = 0;
        virtual uintptr_t get_virtual_address(uintptr_t physical_address) = 0;
    };
}
#endif