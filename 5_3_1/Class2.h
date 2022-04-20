#ifndef CLASS2_H
#define CLASS2_H
#include "Class1.h"
class Class2 : public Class1
{
public:
	int a2;
	Class2(int a1, int a2);
	virtual int Calculation(int x);
};
#endif