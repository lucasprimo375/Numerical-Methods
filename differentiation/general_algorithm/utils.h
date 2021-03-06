#ifndef UTILS_H
#define UTILS_H

#include <string>

enum Accuracy {One, Two, Three, Four, Five, Six};

double* get_data_points(std::string file_path, int* number_of_points);

void write_result_to_file(double* points, int number_of_points, std::string output_file_name);

#endif
