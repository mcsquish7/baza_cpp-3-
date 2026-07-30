# CMakeList.txt: проект CMake для LeaverDynamicLib_CMake; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project (LeaverDynamicLib_CMake)

# Добавьте источник в исполняемый файл этого проекта.
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS On)
add_library(LeaverDynamicLib SHARED LeaverDynamicLib_CMake.cpp LeaverDynamicLib_CMake.h)
add_executable (LeaverDynamicLib_CMakeExe Leaver.cpp)

target_link_libraries(LeaverDynamicLib_CMakeExe LeaverDynamicLib)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
