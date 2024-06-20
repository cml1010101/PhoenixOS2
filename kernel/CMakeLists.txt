add_executable(kernel "src/kernel.cpp")
target_link_libraries(kernel PRIVATE bootloader)
target_link_options(kernel PRIVATE ${KERNEL_LINK_FLAGS})
target_compile_options(kernel PRIVATE ${KERNEL_COMPILE_FLAGS})