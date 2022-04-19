#include "Class7.h"
Class7::Class7(string Object_Name): Class4(Object_Name),Class5(Object_Name)
{
	this->Object_Name=Object_Name+"_7";
}

string Class7::name_getter()
{
	return this->Object_Name;
}