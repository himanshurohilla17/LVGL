cmake_minimum_required(VERSION 3.16)
project(HelloWorld C CXX)

# Set C++ and C standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

# Include the current directory so files can find lv_conf.h
#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/..")

# Add the LVGL core sub-directory
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../lvgl" "${CMAKE_CURRENT_BINARY_DIR}/build")

# Define your custom source files
set(SOURCES
    main.cpp
)

# Create the executable application
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the LVGL library to your application executable
target_link_libraries(${PROJECT_NAME} PRIVATE lvgl)