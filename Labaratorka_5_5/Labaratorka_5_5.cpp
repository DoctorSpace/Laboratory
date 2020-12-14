#include <iostream>
#include <fstream> 
#include <windows.h>

using namespace std;

int stateMenu;

struct Student{

    char F[15], I[15], O[15], Date[15];
    char Fact[15], Kafedra[15], Group[15];
    char Address[15];

}x[10] {};

// Добавление студентов
void Input(Student* x) {
    ofstream file_out;
    ifstream file_in;

    int n = 0;

    file_out.open("Data.txt", ofstream::app); //открываем файл и добавляет в него новые данные
    file_in.open("Data.txt");

    //Проверка строки
    while (!file_in.eof()) file_in >> x[n].F >> x[n].I >> x[n].O >> x[n].Date; n++; // считываем в массив до конца файла

    cout << "Введите Фамилию: ";
    cin >> x[n].F;
    file_out << x[n].F << "\t";

    cout << "Введите Имя: ";
    cin >> x[n].I;
    file_out << x[n].I << "\t";

    cout << "Введите Отчество: ";
    cin >> x[n].O;
    file_out << x[n].O << "\t";

    cout << "Введите День рождение: ";
    cin >> x[n].Date;
    file_out << x[n].Date << "\t";

    cout << "Введите Факультет: ";
    cin >> x[n].Fact;
    file_out << x[n].Fact << "\t";

    cout << "Введите Кафедру: ";
    cin >> x[n].Kafedra;
    file_out << x[n].Kafedra << "\t";

    cout << "Введите Группу: ";
    cin >> x[n].Group;
    file_out << x[n].Group << "\t";

    cout << "Введите Адресс: ";
    cin >> x[n].Address;
    file_out << x[n].Address << endl;


    cout << "\t\t\t Добавить ещё обучающего? \n" <<
        "\t1 - добавить\n" <<
        "\t2 - не добавлять" << endl;

    cin >> n;

//Проверка на ввод значения
    if (n < 0 or n > 3) { 
        system("cls"); system("color 4");
        cout << "ERROR: Попробуйте заново и введите нормальное значение!!!" << endl;
        system("pause"); system("cls"); system("color 7");

        cout << "\t\t\t Добавить ещё обучающего? \n" <<
            "\t1 - добавить\n" <<
            "\t2 - не добавлять" << endl;

        cin >> n;
    }

    switch (n) {
    case 1:
        system("cls");
        Input(x);
        break;
    case 2:
        system("cls");
        file_out.close();
        file_in.close();
        break;
    default:
        system("cls");
        system("color 4");
        cout << "ERROR: Опять неправильное значение, давай заново!!!" << endl << endl;
        system("pause");
        system("color 7");
        system("cls");
        file_out.close();
        file_in.close();
    }
};

// Считывание базы
void Read() {
    ifstream file_in;

    int value = 0;

    file_in.open("Data.txt", ios_base::in); //Файл открыт только для чтения
    if (!file_in.is_open()) {
        system("cls"); system("color 4");
        cout << "ERROR: Файл не открылся!" << endl << endl;
        system("pause"); system("color 7"); system("cls");
        file_in.close();
    }
    else {
        while (!file_in.eof()) {
            char text[255] =  "" ;
            file_in.getline(text, 255); //считали строку
            cout << text << "\n";
        }
        system("pause");
        system("cls");
    }
    file_in.close();
};

// Сортировка
void Sorted(Student *x) {

    ifstream file_in;
    Student temp;

    int n = 0;
    file_in.open("Data.txt");
    
    while (!file_in.eof()) {

        file_in >> x[n].F >> x[n].I >> x[n].O >> x[n].Date >> x[n].Fact >> x[n].Kafedra >> x[n].Group >> x[n].Address;
        n++; // считываем в массив до конца файла
    }

    if (!file_in.is_open()) {
        system("cls"); system("color 4");
        cout << "ERROR: Файл не открылся!" << endl << endl;
        system("pause"); system("color 7"); system("cls");
    }
    else {

        int state = 0;
        cout << "\t\tСортировать по: " << endl
            << "1 - По Фамилии " << endl
            << "2 - По Имени " << endl
            << "3 - По Отчеству" << endl;
        cin >> state;

        system("cls");

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                switch (state) {
                case 1:
                    if (strcmp(x[i].F, x[j].F) > 0) {   //  x[i].F > x[j].F -> Сортировка по фамилии

                        strcpy_s(temp.F, x[i].F);
                        strcpy_s(temp.I, x[i].I);
                        strcpy_s(temp.O, x[i].O);
                        strcpy_s(temp.Date, x[i].Date);
                        strcpy_s(temp.Fact, x[i].Fact);
                        strcpy_s(temp.Kafedra, x[i].Kafedra);
                        strcpy_s(temp.Group, x[i].Group);
                        strcpy_s(temp.Address, x[i].Address);

                        strcpy_s(x[i].F, x[j].F);
                        strcpy_s(x[i].I, x[j].I);
                        strcpy_s(x[i].O, x[j].O);
                        strcpy_s(x[i].Date, x[j].Date);
                        strcpy_s(x[i].Fact, x[j].Fact);
                        strcpy_s(x[i].Kafedra, x[j].Kafedra);
                        strcpy_s(x[i].Group, x[j].Group);
                        strcpy_s(x[i].Address, x[j].Address);

                        strcpy_s(x[j].F, temp.F);
                        strcpy_s(x[j].I, temp.I);
                        strcpy_s(x[j].O, temp.O);
                        strcpy_s(x[j].Date, temp.Date);
                        strcpy_s(x[j].Fact, temp.Fact);
                        strcpy_s(x[j].Kafedra, temp.Kafedra);
                        strcpy_s(x[j].Group, temp.Group);
                        strcpy_s(x[j].Address, temp.Address);
                    }
                    break;
                case 2:
                    if (strcmp(x[i].I, x[j].I) > 0) {   // Сортировка по имени

                        strcpy_s(temp.F, x[i].F);
                        strcpy_s(temp.I, x[i].I);
                        strcpy_s(temp.O, x[i].O);
                        strcpy_s(temp.Date, x[i].Date);
                        strcpy_s(temp.Fact, x[i].Fact);
                        strcpy_s(temp.Kafedra, x[i].Kafedra);
                        strcpy_s(temp.Group, x[i].Group);
                        strcpy_s(temp.Address, x[i].Address);

                        strcpy_s(x[i].F, x[j].F);
                        strcpy_s(x[i].I, x[j].I);
                        strcpy_s(x[i].O, x[j].O);
                        strcpy_s(x[i].Date, x[j].Date);
                        strcpy_s(x[i].Fact, x[j].Fact);
                        strcpy_s(x[i].Kafedra, x[j].Kafedra);
                        strcpy_s(x[i].Group, x[j].Group);
                        strcpy_s(x[i].Address, x[j].Address);

                        strcpy_s(x[j].F, temp.F);
                        strcpy_s(x[j].I, temp.I);
                        strcpy_s(x[j].O, temp.O);
                        strcpy_s(x[j].Date, temp.Date);
                        strcpy_s(x[j].Fact, temp.Fact);
                        strcpy_s(x[j].Kafedra, temp.Kafedra);
                        strcpy_s(x[j].Group, temp.Group);
                        strcpy_s(x[j].Address, temp.Address);
                    }
                    break;
                case 3:
                    if (strcmp(x[i].O, x[j].O) > 0) {   // Сортировка по имени

                        strcpy_s(temp.F, x[i].F);
                        strcpy_s(temp.I, x[i].I);
                        strcpy_s(temp.O, x[i].O);
                        strcpy_s(temp.Date, x[i].Date);
                        strcpy_s(temp.Fact, x[i].Fact);
                        strcpy_s(temp.Kafedra, x[i].Kafedra);
                        strcpy_s(temp.Group, x[i].Group);
                        strcpy_s(temp.Address, x[i].Address);

                        strcpy_s(x[i].F, x[j].F);
                        strcpy_s(x[i].I, x[j].I);
                        strcpy_s(x[i].O, x[j].O);
                        strcpy_s(x[i].Date, x[j].Date);
                        strcpy_s(x[i].Fact, x[j].Fact);
                        strcpy_s(x[i].Kafedra, x[j].Kafedra);
                        strcpy_s(x[i].Group, x[j].Group);
                        strcpy_s(x[i].Address, x[j].Address);

                        strcpy_s(x[j].F, temp.F);
                        strcpy_s(x[j].I, temp.I);
                        strcpy_s(x[j].O, temp.O);
                        strcpy_s(x[j].Date, temp.Date);
                        strcpy_s(x[j].Fact, temp.Fact);
                        strcpy_s(x[j].Kafedra, temp.Kafedra);
                        strcpy_s(x[j].Group, temp.Group);
                        strcpy_s(x[j].Address, temp.Address);
                    }
                    break;
                default:
                    system("cls"); system("color 4");
                    cout << "ERROR: Введено не правильное значение!" << endl << endl;
                    system("pause"); system("color 7"); system("cls");
                    break; 
                }
            }
        }

        for (int i = 0; i < n; i++) cout << x[i].F << "\t" << x[i].I << "\t" << x[i].O << "\t" << x[i].Date << "\t" << x[i].Fact << "\t" << x[i].Kafedra << "\t" << x[i].Group << "\t" << x[i].Address << endl;  // вывод отсортированного массива
        system("pause");
        system("cls");
        file_in.close();
    }
};

//Функция нахождения 
void Find(Student* x) {
    ifstream file_in;

    int n = 0;
    file_in.open("Data.txt");

    while (!file_in.eof()) {

        file_in >> x[n].F >> x[n].I >> x[n].O >> x[n].Date >> x[n].Fact >> x[n].Kafedra >> x[n].Group >> x[n].Address;
        n++; // считываем в массив до конца файла
    }

    if (!file_in.is_open()) {
        system("cls"); system("color 4");
        cout << "ERROR: Файл не открылся!" << endl << endl;
        system("pause"); system("color 7"); system("cls");
    }
    else { // структура работает!

        char name[15] {};
        int state = 0;

        cout << "\t\tПоиск: "       << endl <<
            "1 - По Фамилии: "      << endl <<
            "2 - По Имени: "        << endl <<
            "3 - По Отчеству: "     << endl <<
            "4 - По дню рождения: " << endl;

        cin >> state;
        system("cls");

        cout << "Введите данные: ";
        cin >> name; cout << endl;

        switch (state) {
        case 1:
            for (int i = 0; i < n; i++) {
                if (strcmp(x[i].F, name) == 0) {
                    cout << x[i].F << "\t" << x[i].I << "\t" << x[i].O << "\t" << x[i].Date << "\t" << x[i].Fact << "\t" << x[i].Kafedra << "\t" << x[i].Group << "\t" << x[i].Address << endl;
                }
            }
            system("pause");
            system("cls");
            break;
        case 2:
            for (int i = 0; i < n; i++) {
                if (strcmp(x[i].I, name) == 0) {
                    cout << x[i].F << "\t" << x[i].I << "\t" << x[i].O << "\t" << x[i].Date << "\t" << x[i].Fact << "\t" << x[i].Kafedra << "\t" << x[i].Group << "\t" << x[i].Address << endl;
                }
            }
            system("pause");
            system("cls");
            break;
        case 3:
            for (int i = 0; i < n; i++) {
                if (strcmp(x[i].O, name) == 0) {
                    cout << x[i].F << "\t" << x[i].I << "\t" << x[i].O << "\t" << x[i].Date << "\t" << x[i].Fact << "\t" << x[i].Kafedra << "\t" << x[i].Group << "\t" << x[i].Address << endl;
                }
            }
            system("pause");
            system("cls");
            break;
        case 4:
            for (int i = 0; i < n; i++) {
                if (strcmp(x[i].Date,name) == 0) {
                    cout << x[i].F << "\t" << x[i].I << "\t" << x[i].O << "\t" << x[i].Date << "\t" << x[i].Fact << "\t" << x[i].Kafedra << "\t" << x[i].Group << "\t" << x[i].Address << endl;
                }
            }
            system("pause");
            system("cls");
            break;
        default:
            system("cls"); system("color 4");
            cout << "ERROR: Введено не правильное значение!" << endl << endl;
            system("pause"); system("color 7"); system("cls");
        }
    }
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

    MainMenu();

    while (stateMenu != 0){
        switch (stateMenu) {
        case 1:               //Добавление участника
            system("cls");
            Input(x);
            MainMenu();
            break; 
        case 2:               //Проверить список
            system("cls");
            Read();
            MainMenu();
            break;
        case 3:              //Сортировать список
            system("cls");
            Sorted(x); 
            MainMenu();
            break;
        case 4:              //Найти участника
            system("cls");
            Find(x); 
            MainMenu();
            break;
        default:
            system("cls"); system("color 4");
            cout << "ERROR: Попробуйте заново и введите нормальное значение!!!" << endl << endl;
            system("pause"); system("color 7"); system("cls");
            MainMenu();
        }
    }
}
