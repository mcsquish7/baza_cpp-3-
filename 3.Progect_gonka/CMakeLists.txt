# CMakeList.txt: проект CMake для MODULE_3_gonki; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project (MODULE_3_gonki)

# Добавьте источник в исполняемый файл этого проекта.
set (CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS On)

set (HEADERS 
headers/Ground_vehicle.h 
headers/Air_vehicle.h 
headers/Vehicle.h 
headers/Camel.h 
headers/Camel_fast.h 
headers/Kentavr.h 
headers/Boots_rover.h 
headers/Broom.h 
headers/Eagle.h 
headers/Flying_carpet.h
)

set (SOURCES 
classes/Ground_vehicle.cpp 
classes/Air_vehicle.cpp 
classes/Vehicle.cpp 
classes/Camel.cpp 
classes/Camel_fast.cpp 
classes/Kentavr.cpp 
classes/Boots_rover.cpp 
classes/Broom.cpp 
classes/Eagle.cpp 
classes/Flying_carpet.cpp 
)

# set (GLOB HEADERS "../headers/*.h")
# set (GLOB SOURCES "../classes/*.cpp")

add_library(GonkaCMakeDynLib SHARED ${SOURCES} ${HEADERS})

# Добавьте источник в исполняемый файл этого проекта.
add_executable (MODULE_3_gonkiExe MODULE_3_gonki.cpp)

target_link_libraries(MODULE_3_gonkiExe GonkaCMakeDynLib)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
