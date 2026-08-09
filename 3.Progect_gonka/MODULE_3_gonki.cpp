// MODULE_3_gonki.cpp: определяет точку входа для приложения.
//
#include <iostream>
#include "headers/Camel.h"
#include "headers/Camel_fast.h"
#include "headers/Kentavr.h"
#include "headers/Boots_rover.h"
#include "headers/Broom.h"
#include "headers/Eagle.h"
#include "headers/Flying_carpet.h"

using namespace std;

enum VehicleType {
	BOOTS_ROVER = 1,
	BROOM = 2,
	CAMEL = 3,
	KENTAVR = 4,
	EAGLE = 5,
	CAMEL_FAST = 6,
	FLYING_CARPET = 7
};

void print_registration_menu(int race_type, double distance, const string& names, int count) {
	cout << "Гонка для ";
	if (race_type == 1)
		cout << "наземного транспорта";
	else if (race_type == 2)
		cout << "воздушного транспорта";
	else
		cout << "наземного и воздушного транспорта";
	cout << ". Расстояние " << distance << '\n';

	if (count != 0) {
		cout << "Зарегистрированные транспортные средства: " << names << '\n';
	}

	cout << "1. Ботинки-вездеходы\n";
	cout << "2. Метла\n";
	cout << "3. Верблюд\n";
	cout << "4. Кентавр\n";
	cout << "5. Орёл\n";
	cout << "6. Верблюд-быстроход\n";
	cout << "7. Ковёр-самолёт\n";
	cout << "0. Закончить регистрацию\n";
	cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
}

bool is_vehicle_allowed(int veh, int race_type) {
	switch (race_type) {
	case 1:
		return (veh == BOOTS_ROVER || veh == CAMEL || veh == KENTAVR || veh == CAMEL_FAST);
	case 2:
		return (veh == BROOM || veh == EAGLE || veh == FLYING_CARPET);
	case 3:
		return (veh >= BOOTS_ROVER && veh <= FLYING_CARPET);
	default:
		return false;
	}
}

bool check_name_list(const int& count, string name_list[], string last_name)
{
	for (int i = 0; i < count; i++)
	{
		if (name_list[i] == last_name)
		{
			cout << "Попытка зарегистрировать неправильный тип транспортного средства!\n";
			return false;
		}
	}
	return true;
}

bool register_vehicle(int veh, double distance, string name_list[], double times[], int& count, string& names) {
	string last_name;

	switch (veh) {
	case BOOTS_ROVER: {
		Boots_rover boots(distance);
		last_name = boots.get_name();
		if (check_name_list(count, name_list, last_name))
		{
			name_list[count] = last_name;
			times[count] = boots.get_time();
			break;
		}
		else return false;	
	}
	case BROOM: {
		Broom br(distance);
		last_name = br.get_name();
		if (check_name_list(count, name_list, last_name))
		{
			name_list[count] = last_name;
			times[count] = br.get_time();
			break;
		}
		else return false;
	}
	case CAMEL: {
		Camel cam(distance);
		last_name = cam.get_name();
		if (check_name_list(count, name_list, last_name))
		{
			name_list[count] = last_name;
			times[count] = cam.get_time();
			break;
		}
		else return false;
	}
	case KENTAVR: {
		Kentavr kent(distance);
		last_name = kent.get_name();
		if (check_name_list(count, name_list, last_name))
		{
			name_list[count] = last_name;
			times[count] = kent.get_time();
			break;
		}
		else return false;
	}
	case EAGLE: {
		Eagle eg(distance);
		last_name = eg.get_name();
		if (check_name_list(count, name_list, last_name))
		{
			name_list[count] = last_name;
			times[count] = eg.get_time();
			break;
		}
		else return false;;
	}
	case CAMEL_FAST: {
		Camel_fast cam_fast(distance);
		last_name = cam_fast.get_name();
		if (check_name_list(count, name_list, last_name))
		{
			name_list[count] = last_name;
			times[count] = cam_fast.get_time();
			break;
		}
		else return false;
	}
	case FLYING_CARPET: {
		Flying_carpet fc(distance);
		last_name = fc.get_name();
		if (check_name_list(count, name_list, last_name))
		{
			name_list[count] = last_name;
			times[count] = fc.get_time();
			break;
		}
		else return false;
	}
	default:
		return false;
	}

	names += (count == 0 ? last_name : ", " + last_name);
	count++;
	return true;
}

void register_vehicles_for_race(int race_type, double distance, string name_list[], double times[], int& count) {
	string names = "";
	bool err = false;

	while (true) {
		if (count != 0 && !err) {
			cout << name_list[count - 1] << " успешно зарегистрирован!\n";
		}

		print_registration_menu(race_type, distance, names, count);

		int veh;
		cin >> veh;
		cout << endl;

		if (veh == 0) break;

		if (!is_vehicle_allowed(veh, race_type)) {
			cout << "Попытка зарегистрировать неправильный тип транспортного средства!\n";
			err = true;
			continue;
		}

		if (register_vehicle(veh, distance, name_list, times, count, names)) {
			err = false;
		}
		else {
			err = true;
		}
	}
}

void print_results(string name_list[], double times[], int count) {
	cout << "Результаты гонки:\n";

	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (times[j] > times[j + 1]) {
				swap(times[j], times[j + 1]);
				swap(name_list[j], name_list[j + 1]);
			}
		}
	}

	for (int i = 0; i < count; i++) {
		cout << i + 1 << ". " << name_list[i] << ". Время: " << times[i] << '\n';
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Добро пожаловать в гоночный симулятор!\n";

	bool end_game = false, end_gonka;
	int race_type = 0, action = 0, veh = 0, last_quest = 0;
	double distance = 1;

	while (end_game == false)
	{
		cout << "1. Гонка для наземного транспорта\n";
		cout << "2. Гонка для воздушного транспорта\n";
		cout << "3. Гонка для наземного и воздушного транспорта\n";
		cout << "Выберите тип гонки: ";
		cin >> race_type;

		cout << "\nУкажите длину дистанции (должна быть положительна): ";
		cin >> distance;
		cout << endl;
		end_gonka = false;
		int count = 0;

		const int MAX_VEHICLES = 7;
		string name_list[MAX_VEHICLES];
		double times[MAX_VEHICLES];

		while (!end_gonka)
		{
			if (count < 2) cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства\n";
			cout << "1. Зарегистрировать транспорт\n";
			if (count >= 2) cout << "2. Начать гонку\n";
			cout << "Выберите действие: ";
			cin >> action;
			cout << endl;

			switch (action)
			{
			case 1:
				register_vehicles_for_race(race_type, distance, name_list, times, count);
				break;

			case 2:
				print_results(name_list, times, count);
				cout << "\n1. Провести ещё одну гонку\n2. Выйти\n";
				cout << "Выберите действие: ";
				cin >> last_quest;
				cout << endl;

				if (last_quest == 2) end_gonka = end_game = true; 
				else end_gonka = true;
				break;
		
			default:
				break;
			}
		}
	}

	return 0;
}
