#include <iostream>
#include <windows.h>

using namespace std;

// какими способами можно вводить число (алгебраическая/тригонометрическая/показательная) форма
// как производить ввод чисел? регулярное выражение/поочередно
// пишу код который принимает действительную и мнимую части поочередно
// и складывая возвращает строку
// бесконечная программа? Сделать массив со ссылками на объекты класса и создавать их в цикле
class ComplexNumbers {
public:
    ComplexNumbers(double realPart1, double realPart2, double imaginaryPart1,
                   double imaginaryPart2) : realPart1(realPart1), realPart2(realPart2),
                   imaginaryPart1(imaginaryPart1), imaginaryPart2(imaginaryPart2) {}

    double getRealPart1() const {
        return realPart1;
    }

    double getRealPart2() const {
        return realPart2;
    }

    double getImaginaryPart1() const {
        return imaginaryPart1;
    }

    double getImaginaryPart2() const {
        return imaginaryPart2;
    }

    string firstNumber() {
        return "(" + to_string(getRealPart1()) + " + " + to_string(getImaginaryPart1()) + "i" + ")";
    }

    string secondNumber() {
        return "(" + to_string(getRealPart2()) + " + " + to_string(getImaginaryPart2()) + "i" + ")";
    }

    string addition() {
        return "Ответ: " + to_string(realPart1 + realPart2) + " + " + to_string(imaginaryPart1 + imaginaryPart2) + "i";
    }

    string substraction() {
        return "Ответ: " + to_string(realPart1 - realPart2) + " + " + to_string(imaginaryPart1 - imaginaryPart2) + "i";
    }
protected:
    double realPart1;// Нужны ли double? Проблема с выводом
    double realPart2;
    double imaginaryPart1;
    double imaginaryPart2;
};

class ChildClass : public ComplexNumbers {
public:
    ChildClass(double realPart1, double realPart2, double imaginaryPart1, double imaginaryPart2) : ComplexNumbers(
            realPart1, realPart2, imaginaryPart1, imaginaryPart2) {}

    string multiply() {
        return "Ответ: " + to_string((realPart1 * realPart2) - (imaginaryPart1 * imaginaryPart2)) + " + " +
        to_string((imaginaryPart1 * realPart2) + (realPart1 * imaginaryPart2)) + "i";
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
    cout << "'+' - сложение" << "\n"
    << "'-' - вычитание" << "\n" <<
    "'*' - умножение"<< "\n" << endl;
    cout << "Выберите действие" << endl;
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

    cout << "Введите через пробел действительную и мнимую части 2 "
            "комплексного числа(Диапазон от -1000 до 1000)" << endl;
    while (!(cin >> realPart2 >> imaginaryPart2) || (realPart2 > 1000 ||
             imaginaryPart2 > 1000 || realPart2 < -1000 || imaginaryPart2 < -1000)) {
        cout << "Ошибка ввода!" << std::endl;
        cin.clear();
        fflush(stdin);
    }

    ComplexNumbers complexNumbers(realPart1, realPart2, imaginaryPart1, imaginaryPart2);



    switch (vibor) {
        case '+': {
            cout << "Введен пример: " << complexNumbers.firstNumber() + " + " + complexNumbers.secondNumber() << endl;
            cout << complexNumbers.addition() << endl;
            break;
        }
        case '-': {
            cout << "Введен пример: " << complexNumbers.firstNumber() + " - " + complexNumbers.secondNumber() << endl;
            cout << complexNumbers.substraction() << endl;
            break;
        }
        case '*': {
            ChildClass childClass(realPart1, realPart2, imaginaryPart1, imaginaryPart2);
            cout << "Введен пример: " << childClass.firstNumber() + " * " + childClass.secondNumber() << endl;
            cout << childClass.multiply() << endl;
            break;
        }
    }
    return 0;
}
