#include <iostream>
#include <string> 
#include <vector>
#include <cstdlib>

#include "string.h"
#include "factory.h"

using namespace std;



void Factory::ListAllObjects()
{
	int n = pObjects.size();

	cout << endl << "Список объектов: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << pObjects[i]->GetName() << endl;;
	}
	cout << endl;
}


void Factory::ShowObject(void)
{
	int item, n;

	n = pObjects.size();

	if (n == 0)
	{
		cout << "Хранилище пустое." << endl;
		return;
	}

	cout << "Выберите номер объекта для показа значения:" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << (i + 1) << ":" << pObjects[i]->GetName() << endl;
	}

	item = SelectItem(n);

	cout << "Значение: ";
	pObjects[item - 1]->Show();

}


void Factory::DeleteObject(void)
{
	int item, n;

	n = pObjects.size(); 

	if (n == 0)
	{
		cout << "Пустое хранилище." << endl;
		return;
	}

	cout << "------------------------------------" << endl;
	cout << "Вы берите номер удаляемого объекта:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << (i + 1) << ":" << pObjects[i]->GetName() << endl;
	}



	item = SelectItem(n);
	item--;

	string name = pObjects[item]->GetName();
	pObjects.erase(pObjects.begin() + item);

	cout << "Объект < " << name << " > удален " << endl;
}

void Factory::AddObject(void)
{
	int item;
	StringObj *pNewObj; 

	string name, value;

	cout << "Выберите тип добавляемого объекта:" << endl;
	cout << "1.Символьная строка" << endl;
	cout << "2.Восьмеричная строка" << endl;
	item = SelectItem(2); 
	cout << "Введите имя:";
	cin >> name;
	cin.get();
	cout << "Введите значение:";

	char buffer[MAX_STRING_LEN];
	cin.getline(buffer, MAX_STRING_LEN);
	value = buffer;

	switch (item)
	{
	case 1: pNewObj = new SymbString(name, value); 
		break;
	case 2: 
		if (isOctString(value) == false)
		{
			cout << endl << "!!!!! Некорректное значение. Должны быть только цифры(0-7)." << endl;
			return;
		}
		pNewObj = new OctString(name, value); 
		break;
	}


	pObjects.push_back(pNewObj);
	cout << "Объект успешно добавлен в хранилище." << endl;
}

void Factory::Operations()
{

	int item;
	char buffer[MAX_STRING_LEN];
	string value;

	cout << "Выберите тип складываемых объектов:" << endl;
	cout << "1.Символьная строка" << endl;
	cout << "2.Восьмеричная строка" << endl;

	item = SelectItem(2); 

	switch (item)
	{
	case 1:
	{	cout << "Введите 1-е значение:";
	cin.getline(buffer, MAX_STRING_LEN);
	value = buffer;
	SymbString s1("", value);

	cout << "Введите 2-е значение:";
	cin.getline(buffer, MAX_STRING_LEN);
	value = buffer;
	SymbString s2("", value);
	SymbString s3 = s1 + s2;
	cout << "Результат сложения: "; s3.Show();
	}break;

	case 2: {	cout << "Введите 1-е значение(только цифры 0-7):";
		
		cin.getline(buffer, MAX_STRING_LEN);
		value = buffer;

		if (isOctString(value) == false)
		{
			cout << endl << "!!!!! Некорректное значение. Должны быть только цифры(0-7)." << endl;
			return;
		}
		OctString os1("", value);

		cout << "Введите 2-е значение (только цифры 0-7):";
	
		cin.getline(buffer, MAX_STRING_LEN);
		value = buffer;
		if (isOctString(value) == false)
		{
			cout << endl << "!!!!! Некорректное значение. Должны быть только цифры(0-7)." << endl;
			return;
		}

		OctString os2("", value);
		SymbString os3 = os1 + os2;
		cout << "Результат сложения: "; os3.Show();
	}break;


	}

}


int Factory::SelectItem(int n)
{
	int item;
	while (true) 
	{
		cin >> item;
		if ((item > 0 && item <= n) && (cin.peek() == '\n'))
		{
			cin.get();
			break; 
		}
		else
		{
			cout << "Ошибочный выбор. Повторите ввод.(от 1 до " << n << "):" << endl;
			cin.clear();

			while (cin.get() != '\n') {}; 

		}
	}
	return item;
}