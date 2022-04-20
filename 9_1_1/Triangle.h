#ifndef _TRIANGLE_
#define _TRIANGLE_
class Triangle
{
private:
	int a, b, c;
	double p;
public:
	Triangle(int a, int b, int c);
	int P();
	double S();
	Triangle operator + (Triangle& other);
	Triangle operator - (Triangle& other);
	void Output();
};
#endif
