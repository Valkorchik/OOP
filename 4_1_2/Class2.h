#ifndef CLASS2_H
#define CLASS2_H
#include "Class1.h"
class Class2:private Class1
{
private:
	string Object_Name;
	int Value;
public:
	Class2(string Object_Name , int Value);
	void Print();
};
#endif