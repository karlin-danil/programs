#include <iostream>
#include <string> 
#include <vector>
#include <cstdlib>

using namespace std;

class Factory
{
	
	std::vector <StringObj*> pObjects;
public:
	Factory() {}
	void AddObject(void);
	void Operations();
	void DeleteObject(void);
	void ListAllObjects();
	void ShowObject(void);
	int SelectItem(int n);
};