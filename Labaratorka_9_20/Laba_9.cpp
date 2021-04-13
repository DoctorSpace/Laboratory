#include <iostream>
#include <list>
#include <iterator>
#include <windows.h>
#include <string>

using namespace std;

struct notebook {

    string data;
    string time;
    string meeting;
    string importance;

};

list<notebook> notebookList;     // <тип данных> <имя контейнера>
notebook April;                  // <значение>
list <notebook> ::iterator it;   // <контейнер><его тип> ::iterator <имя инератора>


// 1 - Добавление данных в начало списка
void GetData_front(list<notebook>& v) {

    cout << endl;
    cout << "Дата: ";
    getline(cin, April.data);
    cout << "Время: ";
    getline(cin, April.time);
    cout << "Встреча: ";
    getline(cin, April.meeting);
    cout << "Важность: ";
    getline(cin, April.importance);


    v.push_front(April);        // Толкать вперёд
    system("cls");
}

// 2 - Добавление данных в конец списка
void GetData_back(list<notebook>& v) {

    cout << endl;
    cout << "Дата: ";
    getline(cin, April.data);
    cout << "Время: ";
    getline(cin, April.time);
    cout << "Встреча: ";
    getline(cin, April.meeting);
    cout << "Важность: ";
    getline(cin, April.importance);


    v.emplace_back(April);      // Поставить обратно
    system("cls");
}

// 5 - Удалить элемент по порядковому номеру
void Delete_Number(list<notebook>& v) {

    it = notebookList.begin();  // С начала
    int num;

    cout << "Введите номер элемента: ";
    cin >> num;
    cin.ignore();

    advance(it, num - 1);       // Продвигать итератр
    notebookList.erase(it);     // Cтереть
    system("cls");
}

// 6 - Удалить элемент по заданной информации
void Delete_by(list<notebook>& v) {

    string text;
    int num;

    cout << "По какому критерию искать?"    << endl
        << "1. Дата"                        << endl
        << "2. Время"                       << endl
        << "3. Встреча"                     << endl
        << "4. Важность"                    << endl;

    cin >> num;
    cin.ignore();

    switch (num) {
    case 1:
        cout << "Введите Дату: ";
        getline(cin, text);

        for (auto& b : v) {
            if (b.data == text) {
                v.remove(b);  // Удалить
            }
        }

        break;

    case 2:
        cout << "Введите Время: ";
        getline(cin, text);

        for (auto& b : v) {
            if (b.time == text) {
                v.remove(b); // Удалить
            }
        }

        break;

    case 3:
        cout << "Введите Встречу: ";
        getline(cin, text);

        for (auto& b : v) {
            if (b.meeting == text) {
                v.remove(b); // Удалить
            }
        }

        break;

    case 4:
        cout << "Введите Важность: ";
        getline(cin, text);

        for (auto& b : v) {
            if (b.importance == text) {
                v.remove(b); // Удалить
            }
        }

        break;
    }
    system("cls");
}

// 7 - Добавить элемент на заданное место списка
void ADD_Number(list<notebook>& v) {

    it = notebookList.begin(); // С начала
    int num;

    cout << "Введите номер элемента: ";
    cin >> num;
    cout << endl;

    advance(it, num - 1);      // Продвигать

    cout << "Дата: ";
    getline(cin, April.data);

    cout << endl;
    cout << "Время: ";
    getline(cin, April.time);

    cout << endl;
    cout << "Встреча: ";
    getline(cin, April.meeting);

    cout << endl;
    cout << "Важность: ";
    getline(cin, April.importance);


    v.insert(it, April);        // Вставить
    system("cls");
}

// 8 - Добавить элемент в середину списка
void ADD_Middle(list<notebook>& v) {

    it = notebookList.begin();  // С начала
    int size = notebookList.size();

    advance(it, size / 2);


    cout << endl;
    cout << "Дата: ";
    getline(cin, April.data);
    cout << "Время: ";
    getline(cin, April.time);
    cout << "Встреча: ";
    getline(cin, April.meeting);
    cout << "Важность: ";
    getline(cin, April.importance);


    v.insert(it, April);        // Вставить <позиция> <значение>
    system("cls");
}

// 9 - Удалить элемент из середины списка
void Delete_Middle(list<notebook>& v) {

    it = notebookList.begin();  // С начала
    int size = notebookList.size();
    int half = size / 2;


    advance(it, half);
    notebookList.erase(it);     // Стереть
    system("cls");
}

// 10 - Вывод элементов на экран
void Output_Data(const list<notebook>& v) {

    cout << endl << "\t\t\t" << "Список Дел" << endl;

    for (const auto& April : v) {

        cout << endl;
        cout << "Дата: " << April.data          << "\t"
            << "Время: " << April.time          << "\t"
            << "Время: " << April.meeting       << "\t"
            << "Время: " << April.importance    << endl;
    }

    system("pause");
    system("cls");
}

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    while (1) {

        int count;
        cout << "Действие:" << endl
            << "1. Добавить элемент в начало списка" << endl
            << "2. Добавить элемент в конец списка" << endl
            << "3. Удалить элемент из начала списка" << endl
            << "4. Удалить элемент из конца списка" << endl
            << "5. Удалить элемент по порядковому номеру" << endl
            << "6. Удалить элемент по заданной информации" << endl
            << "7. Добавить элемент на заданное место списка" << endl
            << "8. Добавить элемент в середину списка" << endl
            << "9. Удалить элемент из середины списка" << endl
            << "10. Вывести элементы списка" << endl << endl;

        cin >> count;
        cin.ignore();

        switch (count) {
        case 1:
            system("cls");
            GetData_front(notebookList);             // Добавление элемента в начало списка
            break;

        case 2:
            system("cls");
            GetData_back(notebookList);             // Добавление элемента в конец списка
            break;

        case 3:
            system("cls");
            notebookList.pop_front();            // Удаление элемента из начала списка
            break;

        case 4:
            system("cls");
            notebookList.pop_back();              // Удалить элемент из конца списка
            break;

        case 5:
            system("cls");
            Delete_Number(notebookList);            // Удалить элемент по порядковому номеру
            break;

        case 6:
            system("cls");
            //Delete_by(notebookList);            // Удалить элемент по заданной информации
            break;

        case 7:
            system("cls");
            ADD_Number(notebookList);           // Добавить элемент на заданное место списка
            break;

        case 8:
            system("cls");
            ADD_Middle(notebookList);            // Добавить элемент в середину списка
            break;

        case 9:
            system("cls");
            Delete_Middle(notebookList);          // Удалить элемент из середины списка
            break;

        case 10:
            system("cls");
            Output_Data(notebookList);           // Вывести элементы списка
            break;
        }
    }
}