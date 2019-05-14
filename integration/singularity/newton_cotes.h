#ifndef NEWTON_COTES_H
#define NEWTON_COTES_H

#include <functional>

class NewtonCotes {
public:
    double estimate(double x_I, double x_F, double precision, std::function<double(double)> f);

protected:
    virtual double calculate(double x_I, double x_F, std::function<double(double)> f) = 0;

private:
    double calculatePartitions(double x_I, double x_F, int number_of_partitions, std::function<double(double)> f);
};

#endif
