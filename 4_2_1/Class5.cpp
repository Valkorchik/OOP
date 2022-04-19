#include "Class5.h"
Class5::Class5(string Object_Name): Class1(Object_Name)
{
	this->Object_Name=Object_Name+"_5";
}

string Class5::name_getter()
{
	return this->Object_Name;
}