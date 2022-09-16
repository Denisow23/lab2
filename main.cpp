#include <iostream>
#include <windows.h>

using namespace std;

// ������ ��������� ����� ������� ����� (��������������/������������������/�������������) �����
// ��� ����������� ���� �����? ���������� ���������/����������
// ���� ��� ������� ��������� �������������� � ������ ����� ����������
// � ��������� ���������� ������
// ����������� ���������? ������� ������ �� �������� �� ������� ������ � ��������� �� � �����
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
    double realPart;// ����� �� double? �������� � �������
    double imaginaryPart;
};

class ChildClass : public ComplexNumbers {
public:
    ChildClass(double realPart, double imaginaryPart) : ComplexNumbers(realPart, imaginaryPart) {}

    ChildClass multiply(ChildClass childClass) {
        return ChildClass(((realPart * childClass.getRealPart()) - (imaginaryPart * childClass.getImaginaryPart())),
                ((imaginaryPart * childClass.getRealPart()) + (realPart * childClass.getImaginaryPart())));
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout.setf(ios_base::fixed);
    double realPart1;
    double realPart2;
    double imaginaryPart1;
    double imaginaryPart2;
    char vibor;
    cout << "'+' - ��������" << "\n"
    << "'-' - ���������" << "\n" <<
    "'*' - ���������"<< "\n" << endl;
    cout << "�������� ��������" << endl;
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

    cout << "������� ����� ������ �������������� � ������ ����� 2 "
            "������������ �����(�������� �� -1000 �� 1000)" << endl;
    while (!(cin >> realPart2 >> imaginaryPart2) || (realPart2 > 1000 ||
             imaginaryPart2 > 1000 || realPart2 < -1000 || imaginaryPart2 < -1000)) {
        cout << "������ �����!" << std::endl;
        cin.clear();
        fflush(stdin);
    }

    ComplexNumbers complexNumbers(realPart1, realPart2, imaginaryPart1, imaginaryPart2);



    switch (vibor) {
        case '+': {
            cout << "������ ������: " << complexNumbers.firstNumber() + " + " + complexNumbers.secondNumber() << endl;
            cout << complexNumbers.addition() << endl;
            break;
        }
        case '-': {
            cout << "������ ������: " << complexNumbers.firstNumber() + " - " + complexNumbers.secondNumber() << endl;
            cout << complexNumbers.substraction() << endl;
            break;
        }
        case '*': {
            ChildClass childClass(realPart1, realPart2, imaginaryPart1, imaginaryPart2);
            cout << "������ ������: " << childClass.firstNumber() + " * " + childClass.secondNumber() << endl;
            cout << childClass.multiply() << endl;
            break;
        }
    }
    return 0;
}
