#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>

using namespace std;
int line_user_1 = 0;		// Расположение первого абонента на линии , для инициализации его
int line_user_2 = 0;		// Расположение второго абонента на линии , для инициализации его
int oper = 0;				// количество операций в info

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

	char name_ser[25];
	char id_ser[10];
	char price_ser[10];
	char min_ser[10];

}serv[4] {};

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
		<< "Построить список услуг, которые использовались \n"
		<< "два клиента в прошедшем году (от момента запуска программы)" << endl << endl;

// Этап первый - считывание номера телефона
		
	char user_name_1[15] {}; // Ввод первого абонента
	char user_name_2[15] {}; // Ввод второго абонента

	cout << "Ведите первого абонента: ";
	cin >> user_name_1; cout << endl;

	cout << "Ведите второго абонента: ";
	cin >> user_name_2; cout << endl;

	ifstream file_in; // Открыли user_id
	file_in.open("user_id.txt");

	int line = 0;
	while (!file_in.eof()) { // Передаём данные в структуру People

		file_in >> people[line].F >> people[line].I >> people[line].O >> people[line].phone >> people[line].date_1 >> people[line].date_2 >> people[line].money_1 >> people[line].money_2;
		if (strcmp(people[line].F, user_name_1) == 0 ) { 

			line_user_1 = line; // позиция первого абонента

		}

		if (strcmp(people[line].F, user_name_2) == 0) {

			line_user_2 = line; // позиция второго абонента
		}

		line++;
	}

	file_in.close(); // Получили телефоны абонентов, закрытли файл user_id
		
// Этап второй - запоминание названия услуги

	ifstream file_2in; // Открыли services
	file_2in.open("services.txt");

	line = 0;

	while (!file_2in.eof()) {

		file_2in >> serv[line].name_ser >> serv[line].id_ser >> serv[line].price_ser >> serv[line].min_ser;
		line++;
	}

	file_2in.close();
			
// Этап третий - считываем даты оказания услуг

	ifstream file_3in; // Открыли info
	file_3in.open("info.txt");

	line = 0;

	while (!file_3in.eof()) { // Передаём данные в структуру info

		file_3in >> info[line].phone >> info[line].id >> info[line].date >> info[line].time >> info[line].price;
		line++;
	}

	oper = line;

	file_3in.close(); // Закрыли info

// Этап четыре -  Определяем  текущий год 

	char year[10] {};
	time_t now;
	struct tm nowLocal;
	now = time(NULL);
	nowLocal = *localtime(&now);

	//  cout << nowLocal.tm_year + 1900; // <- определили какой сейчас год на pc #2020
	
// Этап пять - Выводим какие операции совершал первый пользователь за 2019 год

	ofstream file_out;
	file_out.open("Report.txt");

	// Так как номер выходит за границу перевода из char в int, то разбиваем его на части
	// номера пользователей 1, последние 8 цифр

	char verifiable_phone_user_1[20] = { people[line_user_1].phone[4],people[line_user_1].phone[5],people[line_user_1].phone[6],people[line_user_1].phone[7],people[line_user_1].phone[8],people[line_user_1].phone[9],people[line_user_1].phone[10] };

	int k = 0; // необходима для проверки.
	for (int i = 0; i < oper; i++) { // ходим по всем операциям 

		char year[5] = { info[i].date[6], info[i].date[7], info[i].date[8], info[i].date[9] }; // из 14.10.2019 -> получаем 2019

		// последние 8 цифр в info 
		char compare[20] = { info[i].phone[4], info[i].phone[5], info[i].phone[6], info[i].phone[7], info[i].phone[8], info[i].phone[9], info[i].phone[10] };


////////| Сравниваем, когда была запущена программа и текущий год, а так же сверяем номера из info и user_id
		if (nowLocal.tm_year + 1899 == atoi(year) and atoi(verifiable_phone_user_1) == atoi(compare)) {

			k++;
			file_out << "Абонент "<< user_name_1 << " в прошлом году пользовался услугой: ";

			switch (atoi(info[i].id)) { // считываем int значение info_id
			case 1:
				file_out << serv[0].name_ser << endl;
				break;
			case 2:
				file_out << serv[1].name_ser << endl;
				break;
			case 3:
				file_out << serv[2].name_ser << endl;
				break;
			case 4:
				file_out << serv[3].name_ser << endl;
				break;
			}
		}
	}
	if (k == 0) {

		cout << "Данных о " << user_name_1 << " за прошлый год нету!";
		file_out << "Абонент " << user_name_1 << " в прошлом году не совершал никаких операций" << endl;

	}

// Этап шесть - Выводим какие операции совершал второй пользователь за 2019 год


	// Так как номер выходит за границу перевода из char в int, то разбиваем его на части
	// номера пользователей 2, последние 8 цифр

	char verifiable_phone_user_2[20] = { people[line_user_2].phone[4],people[line_user_2].phone[5],people[line_user_2].phone[6],people[line_user_2].phone[7],people[line_user_2].phone[8],people[line_user_2].phone[9],people[line_user_2].phone[10] };
	int j = 0; // необходима для проверки.


	for (int i = 0; i < oper; i++) { // ходим по всем операциям 

		char year[5] = { info[i].date[6], info[i].date[7], info[i].date[8], info[i].date[9] }; // из 14.10.2019 -> получаем 2019
		// последние 8 цифр в info 
		char compare[20] = { info[i].phone[4], info[i].phone[5], info[i].phone[6], info[i].phone[7], info[i].phone[8], info[i].phone[9], info[i].phone[10] };


////////| Сравниваем, когда была запущена программа и текущий год, а так же сверяем номера из info и user_id
		if (nowLocal.tm_year + 1899 == atoi(year) and atoi(verifiable_phone_user_2) == atoi(compare)) {

			j++;
			file_out << "Абонент "<< user_name_2 <<" в прошлом году пользовался услугой: ";

			switch (atoi(info[i].id)) { // считываем int значение info_id
			case 1:
				file_out << serv[0].name_ser << endl;
				break;
			case 2:
				file_out << serv[1].name_ser << endl;
				break;
			case 3:
				file_out << serv[2].name_ser << endl;
				break;
			case 4:
				file_out << serv[3].name_ser << endl;
				break;
			}
		}
	}
	if (j == 0) {
		cout << "Данных о " << user_name_2 << " за прошлый год нету!";
		file_out << "Абонент " << user_name_2 << " в прошлом году не совершал никаких операций" << endl;
	}
	
	if (j > 0 and k > 0) {

		cout << "Программа завершина успешно!";

	}

	file_out.close();
	return 0;
}