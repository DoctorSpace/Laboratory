#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>

using namespace std;

int oper = 0; // Переменная хранит количество операций
int user = 0; // Переменная хранит количество участников


struct People {

	char F[25];
	char I[25];
	char O[25];
	char phone[20];
	char date_1[20];
	char date_2[20];
	char money_1[10];
	char money_2[10];

}people[10] {};

struct services {

	char name_ser[40];
	char id_ser[10];
	char price_ser[10];
	char min_ser[10];

}serv[11] {};

struct info_serv {

	char phone[20];
	char id[10];
	char date[20];
	char time[20];
	char price[10];

}info[40] {};


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Индивидуальное задание: " << endl
		<< "Получить список клиентов, которые имеют задолженность не более заданной и не \n"
		<<"пользовались услугами в течение предыдущего месяца от момента запуска программы" << endl << endl;

// Считываем Параметры
	ifstream Parametr;
	Parametr.open("Param.txt");
	int line = 0;

	char DANO[10];

	while (!Parametr.eof()) {

		Parametr >> DANO;

	}
	
	// Считываем все данные в структуры

	ifstream file_in; // Открыли user_id
	file_in.open("user_id.txt");

	line = 0;
	while (!file_in.eof()) { // Передаём данные в структуру People

		file_in >> people[line].F >> people[line].I >> people[line].O >> people[line].phone >> people[line].date_1 >> people[line].date_2 >> people[line].money_1 >> people[line].money_2;

		line++;
	}

	user = line; 

	file_in.close(); 

	ifstream file_2in; // Открыли services
	file_2in.open("services.txt");

	line = 0;

	while (!file_2in.eof()) {

		file_2in >> serv[line].name_ser >> serv[line].id_ser >> serv[line].price_ser >> serv[line].min_ser;
		line++;
	}

	file_2in.close();

	ifstream file_3in; // Открыли info
	file_3in.open("info.txt");

	line = 0;

	while (!file_3in.eof()) { // Передаём данные в структуру info

		file_3in >> info[line].phone >> info[line].id >> info[line].date >> info[line].time >> info[line].price;
		line++;
	}

	oper = line; 

	file_3in.close(); // Закрыли info


	ofstream file_out; // открываем файл для отчётов
	file_out.open("Report.txt");

	// Узнаём месяц запуска программы

	time_t rawtime;
	struct tm* timeinfo;
	char month_now[80]; // хранит текущий месяц
	char year_now[80];  // хранит текущий год

	time(&rawtime); // текущая дата в секундах
	timeinfo = localtime(&rawtime); // текущее локальное время, представленное в структуре

	strftime(month_now, 80, "  %m.", timeinfo); // Получаем месяц #12
	strftime(year_now, 80, "  %Y.", timeinfo); // Получаем год	  #2020

	int k = 0; // переменная нужна для проверки

	for (int i = 0; i < user; i++) {
		// Получения списка задолжности не больше заданной 
		if (atoi(people[i].money_1) < atoi(DANO)) {

			for (int j = 0; j < oper; j++) {

				char month_oper[6] = { info[j].date[3] , info[j].date[4] }; // хранит месяц операции
				char year_oper[6] = { info[j].date[6], info[j].date[7], info[j].date[8], info[j].date[9] }; // хранит год операции

				// проверяем пользовались услугами абоненты в прошлом месяце
				if ((atoi(month_now) - 1) == atoi(month_oper) and (atoi(year_now)) == atoi(year_oper)) {

					file_out << "Имеет задолжность " << people[i].F << endl;
					k++;

				}
			}
		}
	}

	file_out.close();

	if (k != 0) {
		cout << "Программа завершина успешно!" << endl;
	}
	else {
		cout << "Клиентов имеющих задолжность " << DANO << " нету!";
	}

	return 0;
}