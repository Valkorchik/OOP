#ifndef CLASS3_H
#define CLASS3_H
#include "Class2.h"
class Class3:private Class2
{
private:
	string Object_Name;
	int Value;
public:
	Class3(string Object_Name , int Value);
	void Print();
};
#endif
