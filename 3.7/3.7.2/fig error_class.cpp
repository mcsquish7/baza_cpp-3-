#include "fig_error_class.h"

fig_error::fig_error(const char* sum_angle) : exception(sum_angle) {}
const char* fig_error::what() const { return exception::what(); };