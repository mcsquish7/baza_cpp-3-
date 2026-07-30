#pragma once
#ifdef LEAVERDYNAMICLIB_EXPORTS
#define LEAVERLIB_API __declspec(dllexport)
#else
#define LEAVERLIB_API __declspec(dllimport)
#endif

#include <string>

namespace Leaver_class
{
	class Leaver
	{
	public:
		LEAVERLIB_API static std::string leave(std::string name);
	};
}
