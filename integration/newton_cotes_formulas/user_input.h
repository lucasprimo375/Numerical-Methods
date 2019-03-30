#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <string>

enum FormulaType {kClosedFormula, kOpenFormula};
enum Degree {kDegreeOne, kDegreeTwo, kDegreeThree, kDegreeFour};

FormulaType choose_formula_type();
Degree choose_degree();
void calculate_integral();
double get_limit(std::string message);
double* get_limits();
double get_precision();

#endif