#include "class_Figure.h"

Figure::Figure(std::string name) { this->name = name; }
void Figure::get_name() { std::cout << name << ":\n"; }
void Figure::get_sides() {}
void Figure::get_angles() {}