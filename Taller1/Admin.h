#pragma once
#include <string>
using namespace std;
class Admin
{
private:
	string rut;
	string id;
public:
	Admin();
	Admin(string rut, string id);
	~Admin();
	string getRut();
	string getId();
};

