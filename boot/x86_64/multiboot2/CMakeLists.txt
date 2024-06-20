include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
set(BOOTLOADER_TARGET_NAME "bootloader")
set(BOOTLOADER_SOURCES "src/header.cpp" "src/entry.cpp")
add_executable(${BOOTLOADER_TARGET_NAME} ${BOOTLOADER_SOURCES})
target_link_options(${BOOTLOADER_TARGET_NAME} PRIVATE -T "${CMAKE_CURRENT_SOURCE_DIR}/linker.ld" -ffreestanding -O2 -nostdlib)
target_link_libraries(${BOOTLOADER_TARGET_NAME} PRIVATE gcc)
target_compile_options(${BOOTLOADER_TARGET_NAME} PRIVATE -Werror -Wall -Wextra -Wpedantic -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable
    -Wno-unused-value -Wno-unused-label -Wno-unused-local-typedefs -Wno-unused-const-variable -Wno-unused-macros)