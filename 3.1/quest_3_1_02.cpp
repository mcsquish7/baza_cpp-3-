#include <iostream>
#include <string>

using namespace std;

struct bank
{
	int num;
	string name;
	double balance;
};

void update_balance(bank &b, double new_balance)
{	
	b.balance = new_balance;
}

int main()
{	
	setlocale(LC_ALL, "Russian");
	bank b;
	double new_balance = 0;

	cout << "Введите номер счёта: ";
	cin >> b.num;
	cout << "Введите имя владельца: ";
	cin >> b.name;
	cout << "Введите баланс: ";
	cin >> b.balance;
	cout << "Введите новый баланс: ";
	cin >> new_balance;

	update_balance(b, new_balance);

	cout << "Ваш счёт: " << b.name << ", " << b.num << ", " << b.balance;

	return 0;
}