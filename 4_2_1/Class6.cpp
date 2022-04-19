#include "Class6.h"
Class6::Class6(string Object_Name): Class2(Object_Name), Class3(Object_Name)
{
	this->Object_Name=Object_Name+"_6";
}

string Class6::name_getter()
{
	return this->Object_Name;
}