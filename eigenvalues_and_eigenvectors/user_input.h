#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <string>

#include "methods.h"

namespace UserInput {
	Method get_method();

	std::string get_matrix_file();

	int get_matrix_size();
};

#endif