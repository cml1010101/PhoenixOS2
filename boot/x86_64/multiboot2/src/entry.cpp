#include <cstdint>
extern "C" __attribute__((section(".multiboot.text"))) void _start()
{
    *(uint8_t*)0xb8000 = 'H';
    asm volatile("cli");
    asm volatile("hlt");
    while (true)
    {
    }
}