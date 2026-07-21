#include <iostream>
#include <string>

using namespace std;

class bad_lenght : exception
{
public:
	const char* what() const override { return "Вы ввели слово запретной длины! До свидания"; }
};

int function(string str, int forbidden_lenght)
{
	if (str.length() == forbidden_lenght)
	{
		throw bad_lenght();
	}
	else
	{
		return str.length();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int err_length = 0;
	string word="";
	cout << "Введите запретную длину: ";
	cin >> err_length;
	while (true)
	{
		cout << "Введите слово: ";
		cin >> word;
		try
		{
			int len_word = function(word, err_length);
			cout << "Длина слова '" << word << "' равна " << len_word << '\n';
		}
		catch(bad_lenght& ex)
		{
			cout << ex.what();
			break;
		}
	}
	

	return 0;
}