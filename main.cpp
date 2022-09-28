#include <iostream>
#include <windows.h>
#include "ComplexNumbers.h"
#include "ChildClass.h"
using namespace std;

// какими способами можно вводить число (алгебраическая/тригонометрическая/показательная) форма
// как производить ввод чисел? регулярное выражение/поочередно
// пишу код который принимает действительную и мнимую части поочередно
// и складывая возвращает строку
// бесконечная программа? Сделать массив со ссылками на объекты класса и создавать их в цикле
/** С точки зрения инкапсуляции правильно ли будет в конструктор засунуть исключения? **/
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
//    double realPart;// Нужны ли double? Проблема с выводом
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
    cout << "Денисов Даниил Алексеевич. Группа А-17-21. Лабораторная работа 2."
            " Простейшие классы, одиночное наследование" << endl;
    cout << "Выберете действие, которое хотите выполнить с комплексными числами" << endl;
    cout << "'+' - сложение" << "\n"
    << "'-' - вычитание" << "\n" <<
    "'*' - умножение"<< "\n" << endl;
    cout << "Ваш выбор: " << endl;
    while (!(cin >> vibor) || (vibor != '+' &&
            vibor != '-' && vibor != '*')) {
        cout << "Ошибка ввода!" << std::endl;
        cin.clear();
        fflush(stdin);
    }

    cout << "Введите через пробел действительную и мнимую части 1 "
            "комплексного числа(Диапазон от -1000 до 1000)" << endl;
    while (!(cin >> realPart1 >> imaginaryPart1) || (realPart1 > 1000 ||
            imaginaryPart1 > 1000 || realPart1 < -1000 || imaginaryPart1 < -1000)) {
        cout << "Ошибка ввода!" << std::endl;
        cin.clear();
        fflush(stdin);
    }

    ComplexNumbers complexNumber1(realPart1, imaginaryPart1);

    cout << "Введите через пробел действительную и мнимую части 2 "
            "комплексного числа(Диапазон от -1000 до 1000)" << endl;
    while (!(cin >> realPart2 >> imaginaryPart2) || (realPart2 > 1000 ||
             imaginaryPart2 > 1000 || realPart2 < -1000 || imaginaryPart2 < -1000)) {
        cout << "Ошибка ввода!" << std::endl;
        cin.clear();
        fflush(stdin);
    }

    ComplexNumbers complexNumber2(realPart2, imaginaryPart2);

    switch (vibor) {
        case '+': {
            cout << "Введен пример: " << complexNumber1.toString() + " + " + complexNumber2.toString() << endl;
            cout << "Ответ: " << complexNumber1.addition(complexNumber2).toString() << endl;
            break;
        }
        case '-': {
            cout << "Введен пример: " << complexNumber1.toString() + " - " + complexNumber2.toString() << endl;
            cout << "Ответ: " << complexNumber1.substraction(complexNumber2).toString() << endl;
            break;
        }
        case '*': {
            ChildClass childClass1(realPart1, imaginaryPart1);
            ChildClass childClass2(realPart2, imaginaryPart2);
            cout << "Введен пример: " << childClass1.toString() + " * " + childClass2.toString() << endl;
            cout << "Ответ: " << childClass1.multiply(childClass2).toString() << endl;
            break;
        }
        default : {
            cout << "Ошибка выполнения программы!" << endl;
            exit(1);
        }
    }
    return 0;
}
