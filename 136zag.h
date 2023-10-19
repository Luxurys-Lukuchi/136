// Функция для вывода массива на экран
void printArray(double arr[], int size);

// Функция для чтения массива из файла
void readArrayFromFile(double arr[], int& size, const std::string& filename);

// Функция для вывода массива в файл
void writeArrayToFile(double arr[], int size, const std::string& filename);

// Функция для вывода массива в типизированный файл
template <typename T>
void writeArrayToTypedFile(T arr[], int size, const std::string& filename);

// Функция для вычисления суммы элементов массива по условию: a1 - a2 + a3 - a4 + ... + (-1)^(n+1) * an
double calculateSum(double arr[], int size);