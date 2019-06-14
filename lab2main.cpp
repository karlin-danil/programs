#include <iostream>
#include <string> 
#include <vector>
#include <cstdlib>

#include "string.h"
#include "factory.h"

using namespace std;


int main(void)
{
	
	setlocale(0, "Russian");

	Factory factory;
	bool bQuit;
	int item;

	system("cls");

	bQuit = false;

	
	while (!bQuit)
	{
		
		cout << "1.Добавить объект" << endl;
		cout << "2.Список всех объектов" << endl;
		cout << "3.Показать значение объекта" << endl;
		cout << "4.Операции с объектами" << endl;
		cout << "5.Удалить объект" << endl;
		cout << "6.Выход из программы" << endl;


		item = factory.SelectItem(6);

		switch (item)
		{
		case 1: factory.AddObject(); break;
		case 2: factory.ListAllObjects(); break;
		case 3: factory.ShowObject(); break;
		case 4: factory.Operations(); break;
		case 5: factory.DeleteObject(); break;
		case 6: bQuit = true; break;

		}

	}


}