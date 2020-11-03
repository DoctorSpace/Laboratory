#include <iostream>

using namespace std;

int main(){

    cout << "\n \n\tЛабораторная 2 Вариант 5:\n Нахождение отрицательных чисел и их произведение.\n \n \n";
    setlocale(LC_ALL, "Russian"); // Для RUS.
    
    int n, count = 1;
    cout << "Введите число массива: ";
    cin >> n;
    int a[n];
//Добавление чисел в массив.
    for (int i = 0; i < n; i++){   
        cout << "\nВведите " << i+1 << " число: "; 
        cin >> a[i];
    }
//Функция нахождения отрицательных чисел и их произведение
    for (int i = 0; i < n; i++){
        if (a[i] < 0){
            count = a[i] * count; 
        }
    }
//Вывод произведения
    cout << "\nПроизведение всех отрицательных чисел равна = " << count;
}