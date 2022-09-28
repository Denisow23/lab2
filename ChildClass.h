//
// Created by Admin on 28.09.2022.
//
#include <iostream>
#include "ComplexNumbers.h"
#ifndef LAB2_CHILDCLASS_H
#define LAB2_CHILDCLASS_H

using namespace std;

class ChildClass : public ComplexNumbers {
public:
    ChildClass(double realPart, double imaginaryPart) : ComplexNumbers(realPart, imaginaryPart) {}

    ChildClass multiply(ChildClass childClass) {
        return ChildClass(((realPart * childClass.getRealPart()) - (imaginaryPart * childClass.getImaginaryPart())),
                          ((imaginaryPart * childClass.getRealPart()) + (realPart * childClass.getImaginaryPart())));
    }
};


#endif //LAB2_CHILDCLASS_H
