﻿#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

/*Цель: Написать программу, которая во вводимом с клавиатуры тексте выберет слова,
заканчивающиеся согласной буквой, и выведет их на экран.

Согласные: б, в, г, д, ж, з, й, к, л, м, н, п, р, с, т, ф, х, ц, ч, ш, щ;
*/


int main() {
	//Добавление русского языка
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int len, space1 = 0, space2 = 0;

	string ch;
	char g[] = "БбВвГгДдЙйЖжЗзКкЛлМмНнПпРрСсТтФфЧчЦцЧчШшЩщ";

	cout << "Введите строку: ";
	getline(cin, ch); //вводим строк

	len = ch.length();//определяем длину строки текста

	for (int i = 0; i < len; i++) {
		for (int n = 0; n <= 41; n++) { // проверка букв на согласную
			if (ch[i] == g[n] && (ch[i + 1] == ' ' || ch[i + 1] == '\0')) { // нахождение последней согласной буквы
				space2 = i + 1; // находим 2-ой пробел
				for (int j = space1; j < space2; j++) { // вывод от крайнего пробела, до последнего
					cout << ch[j]; // выводим слово посимвольно
				}
				cout << " ";
				space1 = space2 + 1; //заменяем первый пробел
			}

			if (ch[i] == ' ' || ch[i] == '\0') {
				space1 = i;
			}
		}
	}
}