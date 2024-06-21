#ifndef KERNEL_KERNEL_HPP
#define KERNEL_KERNEL_HPP
#include <cstdint>
namespace kernel
{
    struct Framebuffer
    {
        uint32_t width;
        uint32_t height;
        uint32_t pitch;
        uint32_t bpp;
        uint32_t framebuffer;
    };
    struct MemoryMap
    {
        uint32_t buffer;
        uint32_t map_size;
        uint32_t map_descriptor_size;
        uint32_t map_descriptor_version;
    };
    extern "C" void kernel_main(Framebuffer* framebuffer, MemoryMap* memory_map);
}
#endif