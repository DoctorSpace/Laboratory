#include <iostream>
#include <fstream>

using namespace std;

// Лабараторная работа | методы сортировки
// Вариант 10

int temp = 0, pivot = 0;

void Bubble_Sort(int* mass, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (mass[j] > mass[j + 1]) {

                temp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = temp;
            }
        }
    }
}

void Merge(int mass[], int first, int last, int size) {

    int middle, start, final, j;

    int* mas = new int[size];

    middle = (first + last) / 2; //вычисление среднего элемента
    start = first; //начало левой части
    final = middle + 1; //начало правой части

    for (j = first; j <= last; j++) { //выполнять от начала до конца
        if ((start <= middle) && ((final > last) || (mass[start] < mass[final]))) {
            mas[j] = mass[start];
            start++;
        }
        else {
            mas[j] = mass[final];
            final++;
        }
    }
    //возвращение результата в список
    for (j = first; j <= last; j++) { mass[j] = mas[j]; }
    delete[]mas;
};

void Merge_Sort(int* mass,int first, int last) {

    int size = last;

    if (first < last)
    {
        Merge_Sort(mass, first, (first + last) / 2);        //сортировка левой части
        Merge_Sort(mass, (first + last) / 2 + 1, last);     //сортировка правой части
        Merge(mass, first, last, size);                           //слияние двух частей
    }
}

void Insertion_Sort(int* mass, int size) {
    for (int j = 1; j < size; j++) {
        temp = mass[j];
        pivot = j - 1;
        while (pivot >= 0 && mass[pivot] > temp) {
            mass[pivot + 1] = mass[pivot];
            pivot = pivot - 1;
            mass[pivot + 1] = temp;
        }
    }
}

void Quick_Sort(int* mass, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    int mid = mass[size / 2];

    //Делим массив
    do {
        // В левой части чила, которые меньше центрального
        while (mass[i] < mid) {
            i++;
        }
        // В правой части пропускаем элементы, которые больше центрального
        while (mass[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            int temp = mass[i];
            mass[i] = mass[j];
            mass[j] = temp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if (j > 0) {
        //"Левый кусок"
        Quick_Sort(mass, j + 1);
    }
    if (i < size) {
        //"Првый кусок"
        Quick_Sort(&mass[i], size - i);
    }
}




int main(){

    setlocale(LC_ALL, "ru");
    unsigned rand_value = 18;    //зерно для создания *рандомных чисел

    ofstream file_out;           // Создаём не сортированный файл
    file_out.open("Sumvol_no_sort.txt");

    ofstream end_file_out;       // Создаём сортированный файл
    end_file_out.open("Sumvol_sort.txt");

    int* mass;  // Указатель для выделения памяти под массив
    int size;   // Длина Значений

    cout << "Введите количество символов = "; 
    cin >> size;

    mass = new int[size] {};       // Динамический массив

    if (!file_out.is_open()) {
        cout << "Ошибка, файл Nсортированный не открылся!" << endl;
    }
    else {
        cout << "Файл Nсортированный открылся" << endl;
       
        srand(rand_value);      // Необходимо для создания рандомных чисел

        for (int i = 0; i < size; i++) {

            mass[i] = rand() % 10;
            file_out << mass[i];
        }

        cout << "Массив заполнен числами" << endl;
        file_out.close();      // Закрываем файл с *рандомными числами
    }

//////////////////////////////////////////////////////////////

    if (!end_file_out.is_open()) {
        cout << "Ошибка, файл-сортированный не открылся!" << endl;
    }
    else {
        cout << "Файл-сортированный открылся" << endl;

        int state;
        cout << "Выберите нужную сортировку: " << endl <<
            "1 - Пузырьком  (Bubble sort)" << endl <<
            "2 - Слиянием   (Merge sort)" << endl <<
            "3 - Вставками  (Insertion sort)" << endl <<
            "4 - Быстрая сортировка (Quick sort)" << endl;

        cin >> state;

        switch (state) {
//Bubble sort
        case 1:
            Bubble_Sort(mass, size);
            for (int i = 0; i < size; i++) { end_file_out << mass[i]; }
            break;
//Merge sort
        case 2:
            Merge_Sort(mass, 0, size);
            for (int i = 0; i < size; i++) { end_file_out << mass[i]; }
            break;
//Insertion sort
        case 3:
            Insertion_Sort(mass, size);
            // вывод в сортированный массив в файл
            for (int i = 0; i < size; i++) { end_file_out << mass[i]; }
            break;
//Quick sort
        case 4:
            Quick_Sort(mass,size);
            for (int i = 0; i < size; i++) { end_file_out << mass[i]; }
            break;
        }
        cout << "Отсортировано!" << endl;
        end_file_out.close(); // Закрываеи отсортированный файл

        return 0;
    }
}