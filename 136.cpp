#include <iostream>
#include <cmath>
//Нечталенко ИЛЬЯ ивт-22
#include <fstream>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include "136modul.cpp"
#include "136zag.h"
#define NDEBUG

const int MAX_SIZE = 100;
const float eps = 1e-3;
int main() {

double c[5] = {1,2,3,4,5};
    assert(fabs(calculateSum(c,5) - 3) == 0);
    double d[5] = {1,2,3,4,6};
    assert(fabs(calculateSum(d,5) - 4) <= eps);
    double e[5] = {1,2,3,4,4};
    assert(fabs(calculateSum(e,5) - 2) <= eps);

    try {
        int n;
        std::cout << "Выберите способ заполнения массива:" << std::endl;
        std::cout << "1. Заполнить массив случайными числами" << std::endl;
        std::cout << "2. Считать значения из файла" << std::endl;

        int choice;
        std::cin >> choice;

        double arr[MAX_SIZE];

        if (choice == 1) {
            std::cout << "Введите значение n (не более " << MAX_SIZE << "): ";
            std::cin >> n;
            srand(time(0));
            for (int i = 0; i < n; i++) {
                arr[i] = (rand() % 100) / 10.0; // Генерация случайного числа от 0 до 10 с точностью до одного знака после запятой
            }
        } else if (choice == 2) {
            std::string filename;
            std::cout << "Введите имя файла: ";
            std::cin >> filename;
            readArrayFromFile(arr, n, filename);
        } else {
            throw std::runtime_error("Некорректный выбор.");
        }

        std::cout << "Массив: ";
        printArray(arr, n);

        try {
            double sum = calculateSum(arr, n);
            std::cout << "Сумма: " << sum << std::endl;

            // Проверка суммы с помощью assert
            assert(sum == calculateSum(arr, n));

            // Запись массива в файл
            writeArrayToFile(arr, n, "output.txt");

            // Запись массива в типизированный файл
            writeArrayToTypedFile(arr, n, "output.bin");
        } catch (const std::exception& e) {
            std::cout << "Ошибка при выполнении операций с массивом: " << e.what() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    return 0;
}