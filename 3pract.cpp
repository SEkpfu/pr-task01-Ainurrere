#include <iostream>
using namespace std;

// Функция для ввода данных о работнике и расчета зарплаты
void worker() {
    double hours;    // количество отработанных часов
    double payment;     // ставка почасовой оплаты 
    double prem_percent;   // процент премии
  
    cout << "Введите количество отработанных часов: ";
    cin >> hours;
    
    cout << "Введите ставку почасовой оплаты (руб./час): ";
    cin >> payment;
    
    cout << "Введите процент премии: ";
    cin >> prem_percent;
    
    // Расчеты
    double base_ZP = hours * payment;          // основная зарплата
    double prem = base_ZP * (prem_percent / 100); // сумма премии
    double total_ZP = base_ZP + prem;         // общая зарплата
    
    // Вывод результатов
    cout << "Результаты расчета" << endl;
    cout << "Основная зарплата: " << base_ZP << " руб." << endl;
    cout << "Премия (" << prem_percent << "%): " << prem << " руб." << endl;
    cout << "Сумма на руки: " << total_ZP << " руб." << endl;
}

int main() {

    worker();
    
    return 0;
}