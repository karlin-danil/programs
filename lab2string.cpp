#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <vector>
#include <cstdlib>

#include "string.h"



using namespace std;


void SymbString::Show(void)
{
	cout << value.c_str() << endl;
}


SymbString operator+(SymbString &s1, SymbString &s2)
{
	string ns, vs;
	ns = s1.name + s2.name; 
	vs = s1.value + s2.value;

	return SymbString(ns, vs);
}

//оператор присваивания

SymbString& SymbString::operator=(SymbString &p)
{
	cout << "DEBUG: operator=()" << endl;

	if (this != &p)
	{
		value = p.value;
		name = p.name;
	}
	return *this;
}

// оператор сложения восьмиричных строк
OctString operator+(OctString &os1, OctString &os2)
{
	OctString os;
	char buffer[MAX_STRING_LEN];
	long int o1, o2, sum;

	o1 = os1.GetDecVal();
	o2 = os2.GetDecVal();

	sum = o1 + o2;
	_ltoa(sum, buffer, 8);
	os.value = buffer;
	os.name = os1.GetName() + os2.GetName(); 

	return os;
}

long int OctString::GetDecVal(void)
{
	long int ival;
	int i, ic, len;
	char c;
	const char *p = value.c_str();

	len = value.length();
	i = 1;
	ival = 0; 

	while (len > 0)
	{
		c = p[len - 1];
		ic = c - 48;
		ival += ic * i;
		i *= 8;
		len--;
	}

	return ival;
}



// проверка значения строки на десятичное число
bool isOctString(string s)
{
	const string digits = "01234567";


	for (int i = 0; i < s.size(); i++)
	{
		if (digits.find_first_of(s[i]) == -1)
			return false;
	}
	return true;
}


OctString::OctString() : SymbString() {}

OctString::OctString(std::string _name) : SymbString(_name)
{}

OctString::OctString(std::string _name, std::string _val) : SymbString(_name, _val)
{}



void OctString::Show()
{

	unsigned int uiv;

	uiv = GetDecVal();

	cout.unsetf(ios::dec); 
	cout.setf(ios::oct);  
	cout << uiv << endl;  

	cout.unsetf(ios::oct);
	cout.setf(ios::dec); 


}