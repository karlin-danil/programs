#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{	
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	string text = ""; 
	string search;    
	string result;    
	string filename = "lol.txt"; 

	
	ifstream *in = new ifstream(filename);
	if (in->fail())
	{
		cout << "file '" << filename << "' not found" << endl << endl;
		system("pause");
		return 1;
	}

	
	cout << "enter search  word in proposal: ";
	cin >> search;

	// записываю содержимое файла
	if (in->is_open())
	{
		SetConsoleCP(1251);
		while (!in->eof())
			text += in->get();

		in->close();
		SetConsoleCP(866);
	}
	delete in;

	// позиция с кот осущ поиск
	int find_pos = text.find(search);
	
	if (find_pos == -1)
	{
		cout << "entered word is not found!!!" << endl << endl;
		system("pause");
		return 1;
	}

	// ищу начало строки
	for (int i = find_pos; ; i--)
	{
		if (text[i] != '!' && text[i] != '.' &&
			text[i] != '?' && i != 0)
			find_pos--;
		else
		{
			find_pos = i;
			if (find_pos > 0) find_pos++;
			break;
		}
	}
	// записываю строку
	for (int i = find_pos; ; i++)
	{
		if (text[i] != '!' && text[i] != '.' && text[i] != '?' &&
			(int)text[i] != -1)
		{
			if (i == find_pos && text[i] == ' ') continue;
			result += text[i];
		}
		else break;
	}

	
	cout << result << endl << endl;

	system("pause");
	return 0;
}