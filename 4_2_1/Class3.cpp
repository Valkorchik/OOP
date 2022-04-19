#include "Class3.h"
Class3::Class3(string Object_Name): Class1(Object_Name)
{
	this->Object_Name=Object_Name+"_3";
}

string Class3::name_getter()
{
	return this->Object_Name;
}