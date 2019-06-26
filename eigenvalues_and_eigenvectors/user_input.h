#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <string>

#include "methods.h"
#include "vector.h"

namespace UserInput {
	Method get_method();

	std::string get_matrix_file();

	int get_matrix_size();

	double get_precision();

	Vector* get_initial_guess(int size);
};

#endif