#include <iostream>
#include <string>

#include "user_input.h"
#include "newton_cotes.h"
#include "closed_one.h"
#include "open_one.h"
#include "closed_two.h"
#include "open_two.h"
#include "closed_three.h"
#include "open_three.h"
#include "closed_four.h"
#include "open_four.h"

FormulaType choose_formula_type(){
    int response = 0;

    while(response < 1 || response > 2){
        std::cout << "Choose the formula type(1-Closed, 2-Open)" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> response;
    }


    if(response == 1) return kClosedFormula;

    return kOpenFormula;
}

Degree choose_degree(){
    int response = 0;

    while(response < 1 || response > 4){
        std::cout << "Choose the formula dgree(1, 2, 3, 4)" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> response;
    }

    switch(response){
        case 1: return kDegreeOne;
        case 2: return kDegreeTwo;
        case 3: return kDegreeThree;
        case 4: return kDegreeFour;
    }
}

double f(double d){
    return d*d;
}

void calculate_integral(){
    FormulaType formula_type = choose_formula_type();
    Degree degree = choose_degree();

    NewtonCotes* newton_cotes;
    double result;
    double* limits = get_limits();
    double precision = get_precision();

    switch(formula_type){
        case kClosedFormula:
            switch(degree){
                case kDegreeOne:
                    newton_cotes = new ClosedOne();
                    break;
                case kDegreeTwo:
                    newton_cotes = new ClosedTwo();
                    break;
                case kDegreeThree:
                    newton_cotes = new ClosedThree();
                    break;
                case kDegreeFour:
                    newton_cotes = new ClosedFour();
                    break;
            }
            break;
        case kOpenFormula:
            switch(degree){
                case kDegreeOne:
                    newton_cotes = new OpenOne();
                    break;
                case kDegreeTwo:
                    newton_cotes = new OpenTwo();
                    break;
                case kDegreeThree:
                    newton_cotes = new OpenThree();
                    break;
                case kDegreeFour:
                    newton_cotes = new OpenFour();
                    break;
            }
            break;
    }

    result = newton_cotes->estimate(limits[0], limits[1], precision, &f);

    std::cout << "Result: " << result << std::endl;

    delete[] limits;

    delete newton_cotes;
}

double get_limit(std::string message){
    double limit;

    std::cout << "Input " << message << " limit" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> limit;

    return limit;
}

double* get_limits(){
    std::string lower_message = "lower";
    std::string higher_message = "higher";

    double lower_limit = 1;
    double higher_limit = -1;

    while(higher_limit < lower_limit){
        lower_limit = get_limit(lower_message);
        higher_limit = get_limit(higher_message);
    }

    double* limits = new double[2];

    limits[0] = lower_limit;
    limits[1] = higher_limit;

    return limits;
}

double get_precision(){
    double precision = 0;

    while(precision <= 0){
        std::cout << "Input precision" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> precision;
    }

    return precision;
}