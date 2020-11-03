#include <iostream>
#include <cstring>  // для strlen

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); // Для RUS.
    int n, count = 0, sraref, j;
    cout << "Введите число массива: ";
    cin >> n;
    int a[n];
//Добавление чисел в массив.
    for (int i = 0; i < n; i++){   
        cout << "\nВведите " << i+1 << " число: "; 
        cin >> a[i];
    }
//Функция по нахождению чётных чисел.
    for (int k = 0; k < n; k++){
        if (a[k] % 2 == 0){
            count += a[k];
            j += 1;
            cout << "\n Чётное число = " << a[k] << "\nСумма чётных чисел = " << count << " + " << a[k] << " = " << count + a[k];
        }
        else{
            cout << "Чётных чисел нету";
        }
//Нахожу среднее арифмитическое
    sraref = count / j;
    }
    cout << "\n ------------------------------ \n";
    cout << "Среднее арифмитическое равно = " << sraref; 
}