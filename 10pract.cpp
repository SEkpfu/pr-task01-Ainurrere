#include <iostream>
using namespace std;

int main() {
    const int Workers = 4;
    const int Months = 12; // можно заменить на 12
    
    // Почасовые ставки каждого работника
    double Payment[Workers] = {150.0, 200.0, 180.0, 220.0};
    
    // Отработанные часы (работники x месяцы)
    int hours[Workers][Months] = {
        {160, 150, 170}, // работник 1
        {140, 160, 155}, // работник 2
        {165, 145, 160}, // работник 3
        {150, 155, 165}  // работник 4
    };
    
    // Массив для зарплат и налогов [работник][месяц][0-зарплата, 1-налог]
    double salary[Workers][Months][2];
    
    // Вычисление зарплат и налогов (налог 13%)
    for (int i = 0; i < Workers; i++) {
        for (int j = 0; j < Months; j++) {
            double TotalSalary = Payment[i] * hours[i][j];
            double tax = TotalSalary * 0.13;
            double netSalary = TotalSalary - tax;
            
            salary[i][j][0] = netSalary; // ЗП
            salary[i][j][1] = tax; // Налог    
        }
    }
    
    // Сумма, полученная первым работником на руки во втором месяце
    cout << "1. Первый работник во втором месяце получил на руки: " 
         << salary[0][1][0] << " руб." << endl;
    
    // Общая сумма налога, удержанная у третьего работника за весь год
    double totalTaxWorker3 = 0;
    for (int j = 0; j < Months; j++) {
        totalTaxWorker3 += salary[2][j][1];
    }
    cout << "2. Общий налог третьего работника за год: " 
         << totalTaxWorker3 << " руб." << endl;
    
    // Номер работника, заработавшего больше всех в третьем месяце
    int bestWorker = 0;
    double maxSalary = salary[0][2][0]; 
    for (int i = 1; i < Workers; i++) {
        if (salary[i][2][0] > maxSalary) {
            maxSalary = salary[i][2][0];
            bestWorker = i;
        }
    }
    cout << "3. В третьем месяце больше всех заработал работник №" 
         << (bestWorker + 1) << endl;
    
    // Общая сумма, заработанная всей бригадой за год
    double totalBrigade = 0;
    for (int i = 0; i < Workers; i++) {
        for (int j = 0; j < Months; j++) {
            totalBrigade += salary[i][j][0]; 
        }
    }
    cout << "4. Общая сумма, заработанная бригадой за год: " 
         << totalBrigade << " руб." << endl;
    
    return 0;
}