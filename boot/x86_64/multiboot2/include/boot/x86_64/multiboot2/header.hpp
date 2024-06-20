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
                constexpr header(uint32_t magic, uint32_t architecture, uint32_t header_length, uint32_t checksum) : magic(magic), architecture(architecture), header_length(header_length), checksum(checksum)
                {
                }
            };
            template<int N>
            struct __attribute__((packed)) information_request_tag
            {
                uint16_t type;
                uint16_t flags;
                uint32_t size;
                uint32_t requests[N];
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
                uint32_t start;
                uint32_t end;
                constexpr address_tag(uint32_t start, uint32_t end) : type(6), flags(0), size(sizeof(address_tag)), start(start), end(end)
                {
                }
            };
        } // namespace multiboot2
    } // namespace x86_64
} // namespace boot
#endif