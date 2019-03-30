#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <string>

enum Degree {kDegreeTwo, kDegreeThree, kDegreeFour};

Degree get_user_choice();
void calculate_integral();
double get_limit(std::string message);
double* get_limits();

#endif

