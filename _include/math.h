#ifndef MATH_H
#define MATH_H

#include <random>
#include <QtMath>

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

inline double map(double value, double minX, double maxX, double minY, double maxY) {
    return (value - minX) * (maxY - minY) / (maxX - minX) + minY;
}

#endif // MATH_H
