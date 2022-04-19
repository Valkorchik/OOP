#include "Class1.h"
Class1::Class1(string Object_Name)
{
	this->Object_Name=Object_Name+"_1";
}

string Class1::name_getter()
{
	return this->Object_Name;
}