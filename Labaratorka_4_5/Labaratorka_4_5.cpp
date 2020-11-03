#include <iostream> 
#include <string>
#include <fstream>                            //Функция для взаимодействия с файлами

using namespace std;

int main(){

    cout << "\n \n\tЛабораторная 4 Вариант 5:\n Доработать лабораторную №3, Открыть файл\n изменить в нём ь на ъ и сохранить в новом файле.\n \n \n";
    setlocale(LC_CTYPE, "rus");               // Для RUS.

    int len;

    string path = "Test1.txt";
    string part1 = "Test2.txt";
    string text;
//Добавляем функции и открываем файлы
    ifstream file_in;
    ofstream file_out;
    file_in.open(path);                       //Открывает файл "Test1"
    file_out.open(part1);                     //Открывает файл "Test2"
//Проверяем открылся файл или нет
    if (!file_in.is_open()){                  //выдаёт True если файл открылся
        cout << "Ошибка, файл не открылся!" << endl;
    }
    else{
        cout << "Файл открылся" << endl;
//Считываение букв из файла "Test1.txt"
        while (!file_in.eof()){               //выдаёт True если есть символы в файле "Test1.txt"
            text = "";                        //Необходима для того чтобы не было лишних символов
            getline(file_in, text);           //Считывает одну строку из файла "Test1.txt"
            len = text.length();              //количество символов в тексте
//Функция как из Лабораторной №3
            for (int i = 0; i < len; i++){
                if (text[i] == char(-116)){   // char -116 ь
                        text[i] = char(-118); // char -118 ъ
                }
            }
            file_out << text << endl;         //Добавляет заменённую строку из файла "Test1.txt" в файл "Test2.txt"
        }
    }
    file_out.close();                         //Закрывает "Test2.txt"
    file_in.close();                          //Закрывает "Test1.txt"
    return 0;
}