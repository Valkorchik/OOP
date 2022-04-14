#include "Class2.h"
#include <iostream>
#include <cmath>
Class2::Class2(string Object_Name, int Value): Class1(Object_Name,Value)
{
	this->Object_Name=Object_Name+"_2";
	this->Value=pow(Value,2);
	Print();
}
void Class2::Print()
{
	cout<<this->Object_Name<<" "<<this->Value<<endl;
}