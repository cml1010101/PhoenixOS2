cmake_minimum_required(VERSION 3.24)
project(PhoenixOS2 VERSION 0.1.0 LANGUAGES CXX)
add_subdirectory(boot/x86_64/multiboot2)
add_subdirectory(kernel)