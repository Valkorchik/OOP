#include "Class4.h"
Class4::Class4(string Object_Name): Class1(Object_Name)
{
	this->Object_Name=Object_Name+"_4";
}

string Class4::name_getter()
{
	return this->Object_Name;
}