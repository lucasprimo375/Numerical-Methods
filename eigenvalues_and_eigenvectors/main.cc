#include <string>

#include "methods.h"
#include "user_input.h"

int main() {
	Method method = UserInput::get_method();
	std::string matrix_file = UserInput::get_matrix_file();
	int matrix_size = UserInput::get_matrix_size();

	return 0;
}