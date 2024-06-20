#include <boot/x86_64/multiboot2/header.hpp>
extern "C" void _start();
using namespace boot::x86_64;
struct __attribute__((packed)) multiboot_header
{
    multiboot2::header header{sizeof(multiboot_header)};
    multiboot2::information_request_tag<1> information_request{2};
    multiboot2::entry_address_tag entry_address{_start};
};
constexpr multiboot_header __attribute__((section(".multiboot.text"))) header;