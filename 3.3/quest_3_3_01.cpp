#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Address
{
private:
	string city, street;
	int num_h, num_ap;

public:
	Address(string city, string street, int num_h, int num_ap)
	{
		this->city = city;
		this->street = street;
		this->num_h = num_h;
		this->num_ap = num_ap;
	}
	string get_outfile_addr()
	{
		return (city + ", " + street + ", " + to_string(num_h) + ", " + to_string(num_ap));
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream fin("in.txt");
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла in.txt";
		return -1;
	}
	int addr = 0;
	if (!(fin >> addr))
	{
		cout << "Ошибка чтения файла";
		return -1;
	}
	Address **all_addr = new Address *[addr];
	string city, street;
	int num_h, num_ap;
	for (int i = 0; i < addr; ++i)
	{
		fin >> city >> street >> num_h >> num_ap;
		all_addr[i] = new Address(city, street, num_h, num_ap);
	}
	fin.close();
	ofstream fout("out.txt");
	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла out.txt";
		for (int i = 0; i < addr; i++)
		{
			delete[] all_addr[i];
		}
		delete[] all_addr;
		return -1;
	}
	fout << addr << endl;

	for (int i = addr - 1; i >= 0; --i)
	{
		fout << all_addr[i]->get_outfile_addr() << endl;
	}

	fout.close();

	for (int i = 0; i < addr; i++)
	{
		delete[] all_addr[i];
	}

	delete[] all_addr;

	return 0;
}