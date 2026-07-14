#include <iostream>
#include <string>

using namespace std;

struct addres
{
	string city, street;
	int house, apart, idx;
};

void info(addres addr)
{
	cout << "Город: " << addr.city;
	cout << "\nУлица: " << addr.street;
	cout << "\nНомер дома: " << addr.house;
	cout << "\nНомер квартиры: " << addr.apart;
	cout << "\nИндекс: " << addr.idx;

}

int main()
{	
	setlocale(LC_ALL, "Russian");
	addres msk = {"Москва", "Арбат", 12, 8, 123456};
	addres izhevsk = {"Ижевск", "Пушкина", 59, 143, 953769};

	info(msk);
	cout << "\n\n";
	info(izhevsk);

	return 0;
}