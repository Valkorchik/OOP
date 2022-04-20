#include "Class4.h"
Class4::Class4(int a1, int a2, int a3, int a4) : Class3(a1, a2, a3)
{
	this->a4 = a4;
}
int Class4::Calculation(int x)
{
	return a1 * x + a2 * x * x + a3 * x * x * x + a4 * x * x * x * x;
}