
#include <list>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
class Bus
{
public:
	int getBusNumber()
	{
		return bus_number;
	}

	friend istream& operator >> (istream& in, Bus& bus);
	friend ostream& operator << (ostream& out, const Bus& bus);
 
private:
	int bus_number;
	string driver;
	int route;
};

istream& operator >> (istream& in, Bus& bus)
{
	in >> bus.bus_number;
	in >> bus.driver;
	in >> bus.route;

	return in;
}

ostream& operator << (ostream& out, const Bus& bus)
{
	out << "Информация об автобусе: " << endl;
	out << "Номер автобуса: " << bus.bus_number << endl;
	out << "Инициалы водителя: " << bus.driver << endl;
	out << "Номер маршрута: " << bus.route << endl;

	return out;
}


void inputBus(list<Bus>& buses_in_park)
{
	int count;
	cout << "Введите количество автобусов: ";
	cin >> count;

	cout << "Информация об автобуса представлена в формате:" << endl;
	cout << "Номер автобуса,инициалы водителя,номер маршрута" << endl;

	for (auto i = 0; i < count; ++i)
	{
		Bus bus;
		cout << (i + 1) << ". ";
		cin >> bus;
		buses_in_park.push_back(bus);
	}
}

void BusInPark(const int bus_number,
	list<Bus>& buses_in_park,
	list<Bus>& buses_in_route)
{

	auto it = buses_in_route.begin();
	auto eit = buses_in_route.end();
	for (; it != eit; ++it)
	{
		auto bus = *it;
		if (bus_number == bus.getBusNumber())
		{
			buses_in_route.erase(it);
			buses_in_park.push_back(bus);
			cout << "Автобус с номером " << bus_number << " находится в парке" << endl;
			return;
		}
	}
}

void BusInRoute(const int bus_number,
	list<Bus>& buses_in_park,
	list<Bus>& buses_in_route)
{

	auto it = buses_in_park.begin();
	auto eit = buses_in_park.end();
	for (; it != eit; ++it)
	{
		auto bus = *it;
		if (bus_number == bus.getBusNumber())
		{
			buses_in_park.erase(it);
			buses_in_route.push_back(bus);
			cout << "Автобус с номером " << bus_number << " находится в пути" << endl;
			return;
		}
	}
}

int main()

{
	setlocale(LC_ALL, "rus");
	auto exit_flag = false;

	list<Bus> buses_in_route;
	list<Bus> buses_in_park;

	while (!exit_flag)
	{
		cout << endl;
		cout << "1. Ввод информации об автобусах" << endl;
		cout << "2. Выезд из парка" << endl;
		cout << "3. Въезд в парк" << endl;
		cout << "4. Автобусы которые находятся в парке" << endl;
		cout << "5. Автобусы которые находятся в пути" << endl;
		cout << "6. Выход" << endl;

		char menu_number;
		cout << "ВВедите номер из меню: ";
		cin >> menu_number;

		switch (menu_number)
		{
		case '1':
		{
			cout << "Ввод информации об автобусах " << endl;
			inputBus(buses_in_park);
		}
		break;
		case '2':
		{
			cout << "Выезд из парка " << endl; 

			if (buses_in_park.empty())
			{
				cout << "В парке нету автобусов " << endl;
			}
			else
			{
				int bus_number;
				cout <<" Введите номер автобуса: ";
				cin >> bus_number;
				BusInRoute(bus_number, buses_in_park, buses_in_route);
			}

		}
		break;
		case '3':
		{

			cout << "Въезд в парк" <<endl; 
			if (buses_in_route.empty())
			{
				cout << "нету автобусов в пути" << endl;
			}
			else
			{
				int bus_number;
				cout << "Введите номер автобусов: ";
				cin >> bus_number;
				BusInPark(bus_number, buses_in_park, buses_in_route);
			}
		}
		break;
		case '4':
		{
			cout << "Информация об автобусах в парке" << endl;
			if (buses_in_park.empty())
			{
				cout << "В парке нету автобусов " << endl;
			}
			else
			{
				auto size = buses_in_park.size();
				cout << "Количество автобусов в парке: " << size << endl;
				auto it = buses_in_park.begin();
				auto eit = buses_in_park.end();
				for (; it != eit; ++it)
				{
					auto& item = *it;
					cout << item <<endl;
				}
			}
		}
		break;
		case '5':
		{
			cout << "Информаци об автобусах в дороге" << endl;
			if (buses_in_route.empty())
			{
				cout << "Нет автобусов находящихся в пути" << endl;
			}
			else
			{
				auto size = buses_in_route.size();
				cout << "Количество автобусов в дороге: " << size << endl;
				auto it = buses_in_route.begin();
				auto eit = buses_in_route.end();
				for (; it != eit; ++it)
				{
					auto& item = *it;
					cout << item << endl;
				}
			}
		}
		break;
		case '6':
			exit_flag = true;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}