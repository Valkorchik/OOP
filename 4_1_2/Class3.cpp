#include "Class3.h"
#include <iostream>
#include <cmath>
Class3::Class3(string Object_Name, int Value): Class2(Object_Name,Value)
{
	this->Object_Name=Object_Name+"_3";
	this->Value=pow(Value,3);
	Print();
}
void Class3::Print()
{
	cout<<this->Object_Name<<" "<<this->Value<<endl;
}