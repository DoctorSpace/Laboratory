#include <iostream>
#include <fstream> 
#include <windows.h>

using namespace std;

int stateMenu;


struct  Student{

    char F[15], I[15], O[15];
    //char Fact[15], Kafedra[15], Group[15];
    //char Address[15], progress[15];
    int Date;

};

//Добавление студентов
void Input() {
    ofstream file_out;
    char  text[15];
    int n = 0;

    file_out.open("Test.txt", ofstream::app); //открываем файл и добавляет в него новые данные

    cout << "\t\t\tДобавление Студента\n\n" << endl;
    cout << "Фамилия: ";
    cin >> text;
    file_out << text << "\t";

    cout << "Имя: ";
    cin >> text;
    file_out << text << "\t";

    cout << "Отчество: ";
    cin >> text;
    file_out << text << "\t";

    cout << "Дата рождения: ";
    cin >> text;
    file_out << text << "\n";

    cout << "\t\t\t Добавить ещё обучающего? \n" <<
        "\t1 - добавить\n" <<
        "\t2 - не добавлять" << endl;

    cin >> n;

//Проверка на ввод значения
    if (n < 0 or n > 3) { 
        system("cls");
        system("color 4");
        cout << "ERROR: Попробуйте заново и введите нормальное значение!!!" << endl;
        system("pause");
        system("cls");
        system("color 7");

        cout << "\t\t\t Добавить ещё обучающего? \n" <<
            "\t1 - добавить\n" <<
            "\t2 - не добавлять" << endl;

        cin >> n;
    }

    switch (n) {
    case 1:
        system("cls");
        Input();
        break;
    case 2:
        system("cls");
        file_out.close();
        break;
    default:
        system("cls");
        system("color 4");
        cout << "ERROR: Опять неправильное значение, давай заново!!!" << endl << endl;
        system("pause");
        system("color 7");
        system("cls");
        file_out.close();
    }
};

//Считывание базы
void Read() { //Проверка сколько строк используется в программе
    ifstream file_in;

    int value = 0;

    file_in.open("Test.txt", ios_base::in); //Файл открыт только для чтения
    if (!file_in.is_open()) {
        system("cls");
        system("color 4");
        cout << "ERROR: Файл не открылся!" << endl << endl;
        system("pause");
        system("color 7");
        system("cls");
    }
    else {
        while (!file_in.eof()) {
            char text[255] =  "" ;
            file_in.getline(text, 255); //считали строку
            cout << text << "\n";

            if (strlen(text) == 0) { //проверка налиция данных в базе
                system("cls");
                system("color 4");
                cout << "ERROR: База пуста!" << endl << endl;
                system("pause");
                system("color 7");
                system("cls");
                break;
            }
        }

        system("pause");
        system("cls");
    }
};

//Добавление в Структуру
void Adding() {
    ifstream file_in;

    int value = 0;

    file_in.open("Test.txt", ios_base::in); //Файл открыт только для чтения
    if (!file_in.is_open()) {
        system("cls");
        system("color 4");
        cout << "ERROR: Файл не открылся!" << endl << endl;
        system("pause");
        system("color 7");
        system("cls");
    }
    else {
        while (!file_in.eof()) {
            char text[255] = "";
            file_in.getline(text, 255); //считали строку

            if (strlen(text) == 0)  //проверка налиция данных в базе
                system("cls");
                system("color 4");
                cout << "ERROR: База пуста!" << endl << endl;
                system("pause");
                system("color 7");
                system("cls");
                break; 
        }
        system("pause");
        system("cls");
    }
};



//Сортировка
void Sorted() {


};



//Главное меню 
void MainMenu() { 

    cout << "\t\t\tГлавное меню: \n\n" <<
        "\t1 - Добавить участника \n" <<
        "\t2 - Проверить список \n" <<
        "\t3 - Сортировать список \n" <<
        "\t4 - Найти участника" << endl;
    cin >> stateMenu;

};

int main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student work[100], * ptr;

    MainMenu();

    while (stateMenu != 0){
        switch (stateMenu) {
            //Добавление участника
        case 1:
            system("cls");
            Input();
            MainMenu();
            break;
            //Проверить список
        case 2:
            system("cls");
            Read();
            MainMenu();
            break;
            //Сортировать список
        case 3:
            system("cls");
            Sorted();
            MainMenu();
            break;
            //Найти участника
        case 4:
            system("cls");

            break;
            //Если значение отличается от заданных:
        default:
            system("cls");
            system("color 4");
            cout << "ERROR: Попробуйте заново и введите нормальное значение!!!" << endl << endl;
            system("pause");
            system("color 7");
            system("cls");
            MainMenu();
        }
    }
}
