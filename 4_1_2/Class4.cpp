#include "Class4.h"
#include <iostream>
#include <cmath>
Class4::Class4(string Object_Name, int Value): Class3(Object_Name,Value)
{
	this->Object_Name=Object_Name+"_4";
	this->Value=pow(Value,4);
	Print();
}
void Class4::Print()
{
	cout<<this->Object_Name<<" "<<this->Value<<endl;
}