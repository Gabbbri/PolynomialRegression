#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

struct Data {
    double xp;
    double yp;
};

double* linear_regression (Data*, int);

#endif
