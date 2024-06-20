#ifndef BOOT_X86_64_MULTIBOOT2_HEADER_HPP
#define BOOT_X86_64_MULTIBOOT2_HEADER_HPP
#include <cstdint>
namespace boot
{
    namespace x86_64
    {
        namespace multiboot2
        {
            struct __attribute__((packed)) header
            {
                uint32_t magic;
                uint32_t architecture;
                uint32_t header_length;
                uint32_t checksum;
                constexpr header(uint32_t header_length) : magic(0xE85250D6), architecture(0), header_length(header_length), checksum(-(magic + architecture + header_length))
                {
                }
            };
            template<int N>
            struct __attribute__((packed)) information_request_tag
            {
                uint16_t type;
                uint16_t flags;
                uint32_t size;
                int requests[N];
                template<typename... Args>
                constexpr information_request_tag(Args... args) : type(1), flags(0), size(sizeof(information_request_tag<N>)), requests{args...}
                {
                }
            };
            struct __attribute__((packed)) address_tag
            {
                uint16_t type;
                uint16_t flags;
                uint32_t size;
                uint32_t header_address;
                uint32_t load_address;
                uint32_t load_end_address;
                constexpr address_tag(uint32_t header_address, uint32_t load_address, uint32_t load_end_address) : type(2), flags(0), size(sizeof(address_tag)), header_address(header_address), load_address(load_address),
                    load_end_address(load_end_address)
                {
                }
            };
            struct __attribute__((packed)) entry_address_tag
            {
                uint16_t type;
                uint16_t flags;
                uint32_t size;
                void (*entry_address)();
                constexpr entry_address_tag(void (*entry_address)()) : type(3), flags(0), size(sizeof(entry_address_tag)), entry_address(entry_address)
                {
                }
            };
            struct __attribute__((packed)) console_flags_tag
            {
                uint16_t type;
                uint16_t flags;
                uint32_t size;
                uint32_t console_flags;
                constexpr console_flags_tag(uint32_t console_flags) : type(4), flags(0), size(sizeof(console_flags_tag)), console_flags(console_flags)
                {
                }
            };
            struct __attribute__((packed)) efi_amd64_entry_tag
            {
                uint16_t type;
                uint16_t flags;
                uint32_t size;
                uint32_t entry_address;
                constexpr efi_amd64_entry_tag(uint32_t entry_address) : type(9), flags(0), size(sizeof(efi_amd64_entry_tag)), entry_address(entry_address)
                {
                }
            };
            struct __attribute__((packed)) efi_i386_entry_tag
            {
                uint16_t type;
                uint16_t flags;
                uint32_t size;
                uint32_t entry_address;
                constexpr efi_i386_entry_tag(uint32_t entry_address) : type(8), flags(0), size(sizeof(efi_i386_entry_tag)), entry_address(entry_address)
                {
                }
            };
            struct __attribute__((packed)) framebuffer_tag
            {
                uint16_t type;
                uint16_t flags;
                uint32_t size;
                uint32_t width;
                uint32_t height;
                uint32_t depth;
                constexpr framebuffer_tag(uint32_t width, uint32_t height, uint32_t depth) : type(8), flags(0), size(sizeof(framebuffer_tag)), width(width), height(height), depth(depth)
                {
                }
            };
            struct __attribute__((packed)) module_alignment_tag
            {
                uint16_t type;
                uint16_t flags;
                uint32_t size;
                uint32_t alignment;
                constexpr module_alignment_tag(uint32_t alignment) : type(6), flags(0), size(sizeof(module_alignment_tag)), alignment(alignment)
                {
                }
            };
            struct __attribute__((packed)) efi_boot_services_tag
            {
                uint16_t type;
                uint16_t flags;
                uint32_t size;
                constexpr efi_boot_services_tag() : type(7), flags(0), size(sizeof(efi_boot_services_tag))
                {
                }
            };
            struct __attribute__((packed)) relocatable_header_tag
            {
                uint16_t type;
                uint16_t flags;
                uint32_t size;
                uint32_t min_addr;
                uint32_t max_addr;
                uint32_t align;
                uint32_t preference;
                constexpr relocatable_header_tag(uint32_t min_addr, uint32_t max_addr, uint32_t align, uint32_t preference) : type(9), flags(0), size(sizeof(relocatable_header_tag)), min_addr(min_addr),
                    max_addr(max_addr), align(align), preference(preference)
                {
                }
            };
        } // namespace multiboot2
    } // namespace x86_64
} // namespace boot
#endif