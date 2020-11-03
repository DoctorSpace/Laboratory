#include <iostream>

using namespace std;

int main(){

    cout << "\n \n\tЛабораторная 1 Вариант 5:\n Перевести лот в карат и выразить в унциях.\n \n \n";
    setlocale(LC_ALL, "Russian"); // Для RUS.

    float Lot, Karat, Ounce;

    cout << "Введите Лот = ";
    cin >> Lot;

    cout << "\n \nВ " << Lot << " лотах";
//Перевод из лот в карат 
    Karat = Lot * 63.9862;
    printf("\nРавно Карат = %0.4f", Karat);
//Перевод из карат в унции
    Ounce = Karat / 141.75;
    printf("\nРавно Унции = %0.4f", Ounce);
}