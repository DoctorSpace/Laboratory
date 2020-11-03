#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main(){

    cout << "\n \n \tЛабораторная 3 Вариант 5: \nНаписать текст и изменить в нём ь на ъ.\n \n \n";
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251);

    int len;
    
    string text; // добавляем текст
    getline(cin,text); // добавляем буквы в текст (учитываются все буквы)
    len = text.length(); //количество символов в тексте

//Функция замена ь на ъ
    for (int i = 0; i < len; i++){
        if (text[i] == char(252)){   //char  252 ь
                text[i] = char(250); //char  252 ъ  
        }
    }
//Вывод текста
    cout << text;
    return 0;
}