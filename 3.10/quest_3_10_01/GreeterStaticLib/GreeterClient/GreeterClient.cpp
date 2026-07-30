#include <iostream>
#include "Greeter_class.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    std::string name = "";
    
    std::cout << "Введите имя: ";
    std::cin >> name;

    std::cout << Greeter_class::Greeter::greet(name);

    return 0;
}