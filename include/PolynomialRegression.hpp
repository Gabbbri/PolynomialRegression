#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

struct Data {
    double xp;
    double yp;
};

double* polynomial_regression (Data*, int);

#endif