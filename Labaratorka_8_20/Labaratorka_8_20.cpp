#include <iostream>
#include <stack>
#include <cctype>
#include <map>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

string RPN(string str) {

	string srpn;
	map<char, size_t> map;				// карта весов символов
	map.insert(make_pair('*', 3));
	map.insert(make_pair('/', 3));
	map.insert(make_pair('+', 2));
	map.insert(make_pair('-', 2));
	map.insert(make_pair('(', 1));

	stack<char> stack;

	for (auto c : str) {					// формировка результирующей строки в ОПЗ
											// c эквивалентно str[i]
		if (!isalnum(c) && ('.' != c)){		//Проверка на операцию
			if (')' == c) {
				while (stack.top() != '(') {
					srpn += stack.top();
					stack.pop();
				}
				stack.pop();
			}

			else if ('(' == c) {
				stack.push(c);
			}

			else if (stack.empty() || (map[stack.top()] < map[c])) {
				stack.push(c);
			}

			else {
				do {
					srpn += stack.top();
					stack.pop();
				} while (!(stack.empty() || (map[stack.top()] < map[c])));
				stack.push(c);
			}
		}

		else {
			srpn += c; //Проверка элемента, если число - выводит в конечный результат
		}
	}

	while (!stack.empty()) { // остаток из стека добавляется в результ. строку
		srpn += stack.top();
		stack.pop();
	}
	return srpn;
}

int main() {

	string str;
	ifstream file("input.txt");
	ofstream out("output.txt");

	while (!file.eof()) {
		getline(file, str);
		out << RPN(str) << "\n";
	}

	file.close();
	out.close();
}