#include <iostream>
#include <windows.h>
#include "ComplexNumbers.h"
#include "ChildClass.h"
using namespace std;

// ������ ��������� ����� ������� ����� (��������������/������������������/�������������) �����
// ��� ����������� ���� �����? ���������� ���������/����������
// ���� ��� ������� ��������� �������������� � ������ ����� ����������
// � ��������� ���������� ������
// ����������� ���������? ������� ������ �� �������� �� ������� ������ � ��������� �� � �����
/** � ����� ������ ������������ ��������� �� ����� � ����������� �������� ����������? **/
//class ComplexNumbers {
//public:
//    ComplexNumbers(double realPart, double imaginaryPart) : realPart(realPart), imaginaryPart(imaginaryPart) {}
//
//    double getRealPart() const {
//        return realPart;
//    }
//
//    double getImaginaryPart() const {
//        return imaginaryPart;
//    }
//
//    string toString() {
//        return "(" + to_string(getRealPart()) + " + " + to_string(getImaginaryPart()) + "i" + ")";
//    }
//
//    ComplexNumbers addition(ComplexNumbers complexNumbers) {
//        return ComplexNumbers((realPart + complexNumbers.getRealPart()), (imaginaryPart + complexNumbers.getImaginaryPart()));
//    }
//
//    ComplexNumbers substraction(ComplexNumbers complexNumbers) {
//        return ComplexNumbers((realPart - complexNumbers.getRealPart()), (imaginaryPart - complexNumbers.getImaginaryPart()));
//    }
//
//protected:
//    double realPart;// ����� �� double? �������� � �������
//    double imaginaryPart;
//};
//
//class ChildClass : public ComplexNumbers {
//public:
//    ChildClass(double realPart, double imaginaryPart) : ComplexNumbers(realPart, imaginaryPart) {}
//
//    ChildClass multiply(ChildClass childClass) {
//        return ChildClass(((realPart * childClass.getRealPart()) - (imaginaryPart * childClass.getImaginaryPart())),
//                ((imaginaryPart * childClass.getRealPart()) + (realPart * childClass.getImaginaryPart())));
//    }
//};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout.setf(ios_base::fixed);
    double realPart1;
    double realPart2;
    double imaginaryPart1;
    double imaginaryPart2;
    char vibor;
    cout << "������� ������ ����������. ������ �-17-21. ������������ ������ 2."
            " ���������� ������, ��������� ������������" << endl;
    cout << "�������� ��������, ������� ������ ��������� � ������������ �������" << endl;
    cout << "'+' - ��������" << "\n"
    << "'-' - ���������" << "\n" <<
    "'*' - ���������"<< "\n" << endl;
    cout << "��� �����: " << endl;
    while (!(cin >> vibor) || (vibor != '+' &&
            vibor != '-' && vibor != '*')) {
        cout << "������ �����!" << std::endl;
        cin.clear();
        fflush(stdin);
    }

    cout << "������� ����� ������ �������������� � ������ ����� 1 "
            "������������ �����(�������� �� -1000 �� 1000)" << endl;
    while (!(cin >> realPart1 >> imaginaryPart1) || (realPart1 > 1000 ||
            imaginaryPart1 > 1000 || realPart1 < -1000 || imaginaryPart1 < -1000)) {
        cout << "������ �����!" << std::endl;
        cin.clear();
        fflush(stdin);
    }

    ComplexNumbers complexNumber1(realPart1, imaginaryPart1);

    cout << "������� ����� ������ �������������� � ������ ����� 2 "
            "������������ �����(�������� �� -1000 �� 1000)" << endl;
    while (!(cin >> realPart2 >> imaginaryPart2) || (realPart2 > 1000 ||
             imaginaryPart2 > 1000 || realPart2 < -1000 || imaginaryPart2 < -1000)) {
        cout << "������ �����!" << std::endl;
        cin.clear();
        fflush(stdin);
    }

    ComplexNumbers complexNumber2(realPart2, imaginaryPart2);

    switch (vibor) {
        case '+': {
            cout << "������ ������: " << complexNumber1.toString() + " + " + complexNumber2.toString() << endl;
            cout << "�����: " << complexNumber1.addition(complexNumber2).toString() << endl;
            break;
        }
        case '-': {
            cout << "������ ������: " << complexNumber1.toString() + " - " + complexNumber2.toString() << endl;
            cout << "�����: " << complexNumber1.substraction(complexNumber2).toString() << endl;
            break;
        }
        case '*': {
            ChildClass childClass1(realPart1, imaginaryPart1);
            ChildClass childClass2(realPart2, imaginaryPart2);
            cout << "������ ������: " << childClass1.toString() + " * " + childClass2.toString() << endl;
            cout << "�����: " << childClass1.multiply(childClass2).toString() << endl;
            break;
        }
        default : {
            cout << "������ ���������� ���������!" << endl;
            exit(1);
        }
    }
    return 0;
}
