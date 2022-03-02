#include "Triangle.h"
#include <cmath>
Triangle::Triangle(int a, int b, int c)
{
	a1=a;
	b1=b;
	c1=c;
}
int Triangle::P()
{
	return a1+b1+c1;
}
double Triangle::S()
{
	p=P()*0.5;
	return sqrt(p*(p-a1)*(p-b1)*(p-c1));
}


