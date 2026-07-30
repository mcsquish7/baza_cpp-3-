# CMakeList.txt: проект CMake для FigDynLibCMake; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project (FigDynLibCMake)

# Добавьте источник в исполняемый файл этого проекта.
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS On)

set (HEADERS 
class_Figure.h 
class_Parallelogramm.h 
class_PR_q.h 
class_PR_triangle.h 
class_Quadrilateral.h 
class_RB_triangle.h 
class_Romb.h 
class_RS_triangle.h 
class_Square.h 
class_Triangle.h
)

set (SOURCES 
class_Figure.cpp 
class_Parallelogramm.cpp 
class_PR_q.cpp 
class_PR_triangle.cpp 
class_Quadrilateral.cpp 
class_RB_triangle.cpp 
class_Romb.cpp 
class_RS_triangle.cpp 
class_Square.cpp 
class_Triangle.cpp
)

add_library(FigDynLib SHARED ${SOURCES} ${HEADERS})

add_executable (FigDynLibCMakeExe quest_3_10_05.cpp)

target_link_libraries(FigDynLibCMakeExe FigDynLib)
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
