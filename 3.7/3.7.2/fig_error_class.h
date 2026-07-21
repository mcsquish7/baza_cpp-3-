#pragma once
#include <iostream>

class fig_error: std::exception
{
public:
	fig_error(const char* sum_angle);
	const char* what() const override;
};