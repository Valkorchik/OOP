#include "Class1.h"
#include <iostream>
Class1::Class1(string Object_Name, int Value)
{
	this->Object_Name=Object_Name+"_1";
	this->Value=Value;
	Print();
}

void Class1::Print()
{
	cout<<this->Object_Name<<" "<<this->Value<<endl;
}