//
// Created by Admin on 28.09.2022.
//
#include <iostream>
#ifndef LAB2_COMPLEXNUMBERS_H
#define LAB2_COMPLEXNUMBERS_H

using namespace std;
class ComplexNumbers {
public:
    ComplexNumbers(double realPart, double imaginaryPart) : realPart(realPart), imaginaryPart(imaginaryPart) {}

    double getRealPart() const {
        return realPart;
    }

    double getImaginaryPart() const {
        return imaginaryPart;
    }

    string toString() {
        return "(" + to_string(getRealPart()) + " + " + to_string(getImaginaryPart()) + "i" + ")";
    }

    ComplexNumbers addition(ComplexNumbers complexNumbers) {
        return ComplexNumbers((realPart + complexNumbers.getRealPart()), (imaginaryPart + complexNumbers.getImaginaryPart()));
    }

    ComplexNumbers substraction(ComplexNumbers complexNumbers) {
        return ComplexNumbers((realPart - complexNumbers.getRealPart()), (imaginaryPart - complexNumbers.getImaginaryPart()));
    }

protected:
    double realPart;// Нужны ли double? Проблема с выводом
    double imaginaryPart;
};


#endif //LAB2_COMPLEXNUMBERS_H
