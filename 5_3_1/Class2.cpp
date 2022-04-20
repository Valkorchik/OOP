#include "Class2.h"
int Class2::Calculation(int x)
{
	return a1*x+a2*x*x;
}
Class2::Class2(int a1, int a2) : Class1(a1)
{
	this->a2 = a2;
}
