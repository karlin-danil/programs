#include <iostream>
#include <vector>
#include <string>

#ifndef TRAIN_H
#define TRAIN_H
#endif // TRAIN_H
using namespace std;

class Train
{
public:
	Train& operator =(const Train&);

	int getTrainNumber() const { return m_train_number; }

	friend istream& operator >>(istream&, Train&);
	friend ostream& operator <<(ostream&, const Train&);
private:
	string m_final_destination_name;
	int m_train_number;
	string m_departure_time;
};


Train& Train::operator =(const Train& other)
{
	m_final_destination_name = other.m_final_destination_name;
	m_train_number = other.m_train_number;
	m_departure_time = other.m_departure_time;
	return *this;
}

istream& operator >>(istream& in, Train& obj)
{
	in >> obj.m_final_destination_name;
	in >> obj.m_train_number;
	in >> obj.m_departure_time;
	return in;
}

ostream& operator <<(ostream& out, const Train& obj)
{
	out << "\nTrain coordinates: ";
	out << obj.m_final_destination_name << " ";
	out << obj.m_train_number << " ";
	out << obj.m_departure_time << endl;
	return out;
}


const int train_count = 4;

void sortTrainsByTrainNumber(vector<Train>& vec)
{
	for (auto i = 0; i < train_count - 1; ++i)
	{
		for (auto j = 0; j < train_count - i - 1; ++j)
		{
			if (vec[j].getTrainNumber() > vec[j + 1].getTrainNumber())
			{
				auto temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
			}
		}
	}
}

void printTrainByInputNumber(const vector<Train>& trains, const int train_number)
{
	auto finded_train = false;
	for (auto i = 0; i < train_count; ++i)
	{
		auto& train = trains[i];
		if (train_number == train.getTrainNumber())
		{
			finded_train = true;
			cout << "Finded train with train number " << train_number << " : ";
			cout << trains[i];
		}
	}

	if (!finded_train)
	{
		cout << "No train with train number " << train_number << endl;
	}
}

int main()
{
	auto exit_flag = false;

	vector<Train> trains;

	while (!exit_flag)
	{
		cout << endl;
		cout << "1. Input 8 trains coordinates" << endl;
		cout << "2. Show trains coordinates with input train number" << endl;
		cout << "3. Show trains coordinates sorted by train number" << endl;
		cout << "4. Exit" << endl;
		cout << endl;

		int menu_number;
		cout << "Select option from menu: ";
		cin >> menu_number;

		switch (menu_number)
		{
		case 1:
		{
			if (!trains.empty())
			{
				trains.clear();
			}
			cout << "Please enter train coordinates in format:" << endl;
			cout << "Final destination, train number, departure time" << endl;

			for (auto i = 0; i < train_count; ++i)
			{
				Train train;
				cout << (i + 1) << ". ";
				cin >> train;
				trains.push_back(train);
				cout << endl;
			}

			sortTrainsByTrainNumber(trains);
		}
		break;
		case 2:
		{
			if (trains.empty())
			{
				cout << "No train coordinates" << endl;
			}
			else
			{
				int train_number;
				cout << "Please enter train number: ";
				cin >> train_number;
				printTrainByInputNumber(trains, train_number);
			}
		}
		break;
		case 3:
		{
			if (trains.empty())
			{
				cout << "No train coordinates" << endl;
			}
			else
			{
				for (auto i = 0; i < train_count; ++i)
				{
					cout << trains[i];
				}
			}
		}
		break;
		case 4:
			exit_flag = true;
			break;
		default:
			cout << "Wrong menu number " << endl;
			break;
		}
	}
	return 0;
}

