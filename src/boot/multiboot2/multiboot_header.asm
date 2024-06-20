section .multiboot.header

MULTIBOOT_HEADER_MAGIC equ 0xE85250D6
MULTIBOOT_HEADER_ARCHITECTURE equ 0
MULTIBOOT_HEADER_LENGTH equ multiboot_header_end - multiboot_header_start
MULTIBOOT_CHECKSUM equ -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_ARCHITECTURE + MULTIBOOT_HEADER_LENGTH)

multiboot_header_start:

    dd MULTIBOOT_HEADER_MAGIC
    dd MULTIBOOT_HEADER_ARCHITECTURE
    dd MULTIBOOT_HEADER_LENGTH
    dd MULTIBOOT_CHECKSUM

multiboot_end_tag:
    dw 0
    dw 0
    dd multiboot_end_tag_end - multiboot_end_tag
multiboot_end_tag_end:

multiboot_header_end: