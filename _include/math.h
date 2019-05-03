#ifndef MATH_H
#define MATH_H

#include <random>

inline double clip(double number, double max, double min) {
    if(min > max) return number;
    else if(number < min) return min;
    else if(number > max) return max;
    else return number;
}

inline double randomDouble(double a, double b) {
    double random = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
    return a + (random * (b - a));
}

#endif // MATH_H
