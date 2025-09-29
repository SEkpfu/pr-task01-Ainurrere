#include <iostream>
using namespace std;

// Функции для работы с массивами 
int findMinElement(double arr[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int findMaxElement(double arr[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int counter(double arr[], int size, double value) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > value) {
            count++;
        }
    }
    return count;
}

double sum(double arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Функция для ввода данных о работнике (пункт 3)
void Worker() {
    double data[3]; // массив для хранения данных: [часы, ставка, премия%]
    
    cout << "Введите количество отработанных часов: ";
    cin >> data[0];
    cout << "Введите ставку почасовой оплаты (руб./час): ";
    cin >> data[1];
    cout << "Введите процент премии: ";
    cin >> data[2];
    
    // Расчеты с использованием функций для массивов
    double salary = data[0] * data[1];
    double prem = salary * data[2] / 100;
    double total = salary + prem;
    
    // Создаем массив с результатами расчетов
    double results[3] = {salary, prem, total};
    
    // Вывод результатов с использованием функций для массивов
    cout << "Результаты расчета:" << endl;
    cout << "Основная зарплата: " << results[0] << " руб." << endl;
    cout << "Премия: " << results[1] << " руб." << endl;
    cout << "Итого к выплате: " << results[2] << " руб." << endl;
    
    // Демонстрация использования функций для массивов
    cout << "Анализ данных с использованием функций:" << endl;
    
    // Номер минимального элемента в исходных данных
    int minIndex = findMinElement(data, 3);
    cout << "Минимальное значение и его номер: " << data[minIndex] << " (позиция " << minIndex << ")" << endl;
    
    // Максимальный элемент и его номер в результатах
    int maxIndex = findMaxElement(data, 3);
    cout << "Максимальное значение и его номер: " << data[maxIndex] << " (позиция " << maxIndex << ")" << endl;
    
    // Количество элементов больше 50000 в результатах
    int count = counter(results, 3, 50000);
    cout << "Количество сумм больше 50000 руб.: " << count << endl;
    
    // Сумма всех результатов
    double totalSum = sum(results, 3);
    cout << "Общая сумма всех компонентов: " << totalSum << " руб." << endl;
}

int main() {
    cout << "Расчет зарплаты работника:  " << endl;
    Worker();
    return 0;
}