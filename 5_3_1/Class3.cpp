#include "Class3.h"
Class3::Class3(int a1, int a2, int a3) : Class2(a1, a2)
{
	this->a3 = a3;
}
int Class3::Calculation(int x)
{
	return a1 * x + a2 * x * x + a3 * x * x * x;
}