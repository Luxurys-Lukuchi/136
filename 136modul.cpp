#include <iostream>
#include <fstream>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

// Функция для вывода массива на экран
void printArray(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Функция для чтения массива из файла
// первая строка размерность массива
// вторая строка элементы массива
void readArrayFromFile(double arr[], int& size, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> size;
        for (int i = 0; i < size; i++) {
            file >> arr[i];
        }
        file.close();
        std::cout << "Массив успешно считан из файла " << filename << std::endl;
    } else {
        throw std::runtime_error("Не удалось открыть файл " + filename + " для чтения.");
    }
}

// Функция для вывода массива в файл
// первая строка размерность массива
// вторая строка элементы массива
void writeArrayToFile(double arr[], int size, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << size << std::endl;
        for (int i = 0; i < size; i++) {
            file << arr[i] << " ";
        }
        file.close();
        std::cout << "Массив успешно записан в файл " << filename << std::endl;
    } else {
        throw std::runtime_error("Не удалось открыть файл " + filename + " для записи.");
    }
}

// Функция для вывода массива в типизированный файл
// первая строка размерность массива
// вторая строка элементы массива
template <typename T>
void writeArrayToTypedFile(T arr[], int size, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
        file.write(reinterpret_cast<char*>(arr), size * sizeof(T));
        file.close();
        std::cout << "Массив успешно записан в типизированный файл " << filename << std::endl;
    } else {
        throw std::runtime_error("Не удалось открыть типизированный файл " + filename + " для записи.");
    }
}

// Функция для вычисления суммы элементов массива по условию: a1 - a2 + a3 - a4 + ... + (-1)^(n+1) * an
double calculateSum(double arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            sum += arr[i];
        } else {
            sum -= arr[i];
        }
    }
    return sum;
}
