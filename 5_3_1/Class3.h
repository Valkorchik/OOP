#ifndef CLASS__H
#define CLASS3_H
#include "Class2.h"
class Class3 : public Class2
{
public:
	int a3;
	Class3(int a1, int a2, int a3);
	virtual int Calculation(int x);
};

#endif