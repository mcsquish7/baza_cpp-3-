#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string name = "";
	cout << "Введите имя: ";
	cin >> name;
	cout << "Здравствуйте, " + name + "!";
	return 0;
}