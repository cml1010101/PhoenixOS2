extern "C" __attribute__((section(".multiboot.text"))) void _start()
{
    asm volatile("cli");
    asm volatile("hlt");
    while (true)
    {
    }
}