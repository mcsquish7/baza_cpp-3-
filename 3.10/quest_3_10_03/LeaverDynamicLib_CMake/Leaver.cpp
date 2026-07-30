#include <iostream>
#include "LeaverDynamicLib_CMake.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    std::string name = "";

    std::cout << "¬ведите им€: ";
    std::cin >> name;

    std::cout << Leaver_class::Leaver::leave(name);

    return 0;
}