#include "Admin.h"

Admin::Admin()
{
}

Admin::Admin(string rut, string id)
{
	this->rut = rut;
	this->id = id;
}

Admin::~Admin()
{
	rut = "";
	id = "";
}

string Admin::getRut()
{
	return rut;
}

string Admin::getId()
{
	return id;
}
