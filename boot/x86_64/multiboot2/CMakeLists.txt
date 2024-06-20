include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
add_library(bootloader STATIC "src/header.cpp" "src/entry.cpp")
target_compile_options(bootloader PRIVATE "-ffreestanding" "-O2" "-Wall" "-Wextra" "-fno-exceptions" "-fno-rtti")

set(KERNEL_LINK_FLAGS "-T" "${CMAKE_CURRENT_SOURCE_DIR}/linker.ld" "-ffreestanding" "-O2" "-nostdlib" PARENT_SCOPE)
set(KERNEL_COMPILE_FLAGS "-ffreestanding" "-O2" "-Wall" "-Wextra" "-fno-exceptions" "-fno-rtti" PARENT_SCOPE)
file(COPY "grub.cfg" DESTINATION "${CMAKE_BINARY_DIR}")