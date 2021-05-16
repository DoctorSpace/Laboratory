#include <iostream>
#include <windows.h>

using namespace std;

struct root {

    int info;           //Информационное поле
    root* l, * r;       //Левая и Правая часть дерева
};

root* tree = NULL;      //Объявляем переменную, тип которой структура Дерево

// Запись Дерева
void Push(int a, root** tree) {

    if ((*tree) == NULL) {             //Если дерева не существует

        (*tree) = new root;            //Выделяем память
        (*tree)->info = a;             //Кладем в выделенное место аргументa
        (*tree)->l = (*tree)->r = NULL;   //Очищаем память для следующего роста 
        return;                     
    }

    if (a > (*tree)->info) Push(a, &(*tree)->r);    //Если аргумент а больше, то кладем его вправо
    else Push(a, &(*tree)->l);                      //Иначе кладем его влево
}

// Вывод Дерева
void Print_Tree(root* t, int u) {
    if (t) {

        Print_Tree(t->l, u + 1);
        for (int i = 0; i < u; i++) cout << "   ";
        cout << t->info << endl;
        Print_Tree(t->r, u + 1);
    }
}

// Вывод максимального листа
int Max_leaf(root* t) {

    int result;
    if ((t->l == NULL) && (t->r == NULL)) {
        result = t->info;
    }

    if (t->l) {
        result = Max_leaf(t->l);
    }

    if (t->r) {
        result = Max_leaf(t->r);
    }
    return result;
}



void main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int quantity;                      //Количество элементов
    int number;                        //Число, передаваемое в дерево
    int min;

    cout << "Введите количество элементов: ";
    cin >> quantity;                   //Вводим количество элементов

    for (int i = 0; i < quantity; ++i) {
        cout << "Введите число: ";
        cin >> number;
        Push(number, &tree);
    }

    cout << "Дерево: " << endl;
    Print_Tree(tree, 0);

    cout << "Максимальный лист: " << Max_leaf(tree) << endl;
}