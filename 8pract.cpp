#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите количество работников: ";
    cin >> n;
    
    // Создаем два массива: для часов и ставок
    double* hours = new double[n];
    double* rates = new double[n];
    double* prem = new double[n]; // процент премии
    
    // Ввод данных
    for (int i = 0; i < n; i++) {
        cout << "Работник " << (i + 1) << ":" << endl;
        cout << "Отработано часов: ";
        cin >> hours[i];
        cout << "Ставка (руб/час): ";
        cin >> rates[i];
        cout << "Процент премии: ";
        cin >> prem[i];
    }
    
    // Вычисляем зарплаты и налоги
    double* salaries = new double[n]; // зарплаты до вычета налога
    double* taxes = new double[n];    // суммы налогов
    double* net_salaries = new double[n]; // зарплаты на руки
    
    for (int i = 0; i < n; i++) {
        // Зарплата = часы * ставка + премия
        salaries[i] = hours[i] * rates[i] * (1 + prem[i] / 100);
        // Налог 13%
        taxes[i] = salaries[i] * 0.13;
        // На руки
        net_salaries[i] = salaries[i] - taxes[i];
    }
    
    // Поиск минимальной зарплаты
    int min_index = 0;
    double min_salary = salaries[0];
    for (int i = 1; i < n; i++) {
        if (salaries[i] < min_salary) {
            min_salary = salaries[i];
            min_index = i;
        }
    }
    
    // Поиск максимальной зарплаты
    int max_index = 0;
    double max_salary = salaries[0];
    for (int i = 1; i < n; i++) {
        if (salaries[i] > max_salary) {
            max_salary = salaries[i];
            max_index = i;
        }
    }
    
    // Подсчет работников с зарплатой на руки > 50000
    int count = 0;
    cout << "\nРаботники с зарплатой на руки более 50000 руб.:" << endl;
    for (int i = 0; i < n; i++) {
        if (net_salaries[i] > 50000) {
            count++;
            cout << "Номер " << (i + 1) << ": " << net_salaries[i] << " руб." << endl;
        }
    }
    
    // Общая сумма налогов
    double total_tax = 0;
    for (int i = 0; i < n; i++) {
        total_tax += taxes[i];
    }
    
    // Вывод результатов
    cout << "РЕЗУЛЬТАТЫ" << endl;
    cout << "Меньше всех получил работник №" << (min_index + 1) 
         << ": " << salaries[min_index] << " руб." << endl;
    cout << "Максимальная зарплата: " << max_salary << " руб. (работник №" 
         << (max_index + 1) << ")" << endl;
    cout << "Количество работников с зарплатой > 50000 руб.: " << count << endl;
    cout << "Общая сумма налога: " << total_tax << " руб." << endl;
    
    return 0;
}