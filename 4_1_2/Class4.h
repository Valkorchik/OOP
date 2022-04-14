#ifndef CLASS4_H
#define CLASS4_H
#include "Class3.h"
class Class4:private Class3
{
private:
	string Object_Name;
	int Value;
public:
	Class4(string Object_Name , int Value);
	void Print();
};
#endif
