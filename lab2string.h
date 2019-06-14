#pragma once
#include <iostream>
#include <string> 
#include <vector>
#include <cstdlib>

using namespace std;

#define MAX_STRING_LEN 100 

// Базовый  абстрактный класс
class StringObj
{
public:
	virtual const std::string& GetName() = 0;
	virtual const std::string& GetVal() = 0;
	virtual int GetSize() = 0;
	virtual void Show(void) = 0;
};

//Символьная строка
class SymbString : public StringObj
{
protected:
	std::string name; 
	std::string value;
public:
	
	SymbString() {}
	SymbString(std::string _name) :name(_name) {}
	SymbString(std::string _name, std::string _val) :name(_name), value(_val) {}
	~SymbString() {} 
	SymbString& operator=(SymbString &p);

	virtual const std::string& GetName() { return name; }
	virtual const std::string& GetVal() { return value; }
	virtual int GetSize() { return value.size(); }
	virtual void Show(void);

	friend SymbString operator+(SymbString &s1, SymbString &s2);
};


//Восьмеричная строка
class OctString : public SymbString
{
protected:
	long int GetDecVal(void);
public:
	OctString();
	OctString(std::string _name);
	OctString(std::string _name, std::string _val);
	virtual void Show(void);
	friend OctString operator+(OctString &os1, OctString &os2);

};

SymbString operator+(SymbString &s1, SymbString &s2);
OctString operator+(OctString &os1, OctString &os2);
bool isOctString(string s);