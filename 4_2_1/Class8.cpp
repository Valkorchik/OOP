#include "Class8.h"
Class8::Class8(string Object_Name): Class6(Object_Name), Class7(Object_Name)
{
	this->Object_Name=Object_Name+"_8";
}

string Class8::name_getter()
{
	return this->Object_Name;
}