#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <string>

#include "utils.h"

enum class Derivative {First, Second, Third};

enum class Philosophy {Backward, Central, Forward};

std::string get_file_global_path();

int get_number_of_points();

double get_delta_x();

Derivative get_user_derivative_choice();

Accuracy get_user_accuracy_choice();

std::string get_output_file_name_from_user();

Philosophy get_philosophy_from_user();

#endif
