#include "Greeter_class.h"

namespace Greeter_class
{

	std::string Greeter::greet(std::string str)
	{
		return ("Здравствуйте, " + str + "!");
	}
}