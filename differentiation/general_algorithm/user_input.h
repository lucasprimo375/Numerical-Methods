#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <string>

enum class Derivative {First, Second, Third};

std::string get_file_global_path();

int get_number_of_points();

double get_delta_x();

Derivative get_user_derivative_choice();

#endif
