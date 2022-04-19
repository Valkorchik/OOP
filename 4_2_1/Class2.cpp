#include "Class2.h"
Class2::Class2(string Object_Name): Class1(Object_Name)
{
	this->Object_Name=Object_Name+"_2";
}

string Class2::name_getter()
{
	return this->Object_Name;
}