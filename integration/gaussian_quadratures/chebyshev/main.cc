#include <iostream>

#include "user_input.h"

#ifdef __MINGW32__
	#include <Windows.h>
#endif

int main(){
	std::cout << std::endl << "Calculating Gauss-Chebyshev Integral" << std::endl;
	std::cout << "Integrating f(x)/(sqrt(1 - x^2)) from -1 to 1" << std::endl;
	std::cout << "For this particular example f(x) = x^2" << std::endl;
	std::cout << "You can modify f(x) in the file user_input.cc, then you must recompile the aplication by running make all" << std::endl << std::endl;

	calculate_integral();

#ifdef __MINGW32__
	system("pause");
#endif

	return 0;
}
