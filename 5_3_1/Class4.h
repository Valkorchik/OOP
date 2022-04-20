#ifndef CLASS4_H
#define CLASS4_H
#include "Class3.h"
class Class4 : public Class3 {
public:
	int a4;
	Class4(int a1, int a2, int a3, int a4);
	virtual int Calculation(int x);
};

#endif