#include "class_Counter.h"
#include <iostream>

Counter::Counter() {
	count = 1;
}
Counter::Counter(int count) {
	this->count = count;
}
void Counter::inc() {
	++count;
}
void Counter::dec() {
	--count;
}
void Counter::get_count() {
	std::cout << count << '\n';
}