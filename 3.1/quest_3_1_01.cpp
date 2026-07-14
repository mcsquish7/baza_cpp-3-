#include <iostream>

using namespace std;

enum class seasons
{
	January=1, 
	February, 
	March,
	April, 
	May, 
	June, 
	July, 
	August, 
	September,
	October, 
	November, 
	December
};

int main()
{
	setlocale(LC_ALL, "Russian");
	
	int num=1;
	do
	{	
		cout << "Введите номер месяца: ";
		cin >> num;
		if (num == 0) break;
		seasons season = static_cast<seasons>(num);
		switch (season)
		{
		case seasons::January:
			cout << "Январь\n"; break;
		case seasons::February:
			cout << "Февраль\n"; break;
		case seasons::March:
			cout << "Март\n"; break;
		case seasons::April:
			cout << "Апрель\n"; break;
		case seasons::May:
			cout << "Май\n"; break;
		case seasons::June:
			cout << "Июнь\n"; break;
		case seasons::July:
			cout << "Июль\n"; break;
		case seasons::August:
			cout << "Август\n"; break;
		case seasons::September:
			cout << "Сентябрь\n"; break;
		case seasons::October:
			cout << "Октябрь\n"; break;
		case seasons::November:
			cout << "Ноябрь\n"; break;
		case seasons::December:
			cout << "Декабрь\n"; break;
		default:
			cout << "Неправильный номер!\n";
			break;
		}
	} while (true);
	cout << "До свидания";
	

	return 0;
}