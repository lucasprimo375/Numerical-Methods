#ifndef NEWTON_COTES_H
#define NEWTON_COTES_H

class NewtonCotes {
public:
    double estimate(double x_I, double x_F, double precision);

protected:
    virtual double calculate(double x_I, double x_F) = 0;

    virtual double G(double x) = 0;

private:
    double calculatePartitions(double x_I, double x_F, int number_of_partitions);
};

#endif
