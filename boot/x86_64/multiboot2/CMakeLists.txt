include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
set(BOOTLOADER_TARGET_NAME "bootloader")
set(BOOTLOADER_SOURCES "src/header.cpp")
add_executable(${BOOTLOADER_TARGET_NAME} ${BOOTLOADER_SOURCES})