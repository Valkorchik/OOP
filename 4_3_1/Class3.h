#ifndef CLASS3_H
#define CLASS3_H
#include "Class1.h"
#include "Class2.h"
class Class3:public Class1,public Class2
{
public:
	void Executor();
};
#endif
