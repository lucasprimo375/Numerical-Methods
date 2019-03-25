#ifndef NEWTON_COTES_H
#define NEWTON_COTES_H

class NewtonCotes {
public:
    double estimate(double x_I, double x_F, double precision, double (*f)(double));

protected:
    virtual double calculate(double x_I, double x_F, double (*f)(double)) = 0;

private:
    double calculatePartitions(double x_I, double x_F, int number_of_partitions, double (*f)(double));
};

#endif