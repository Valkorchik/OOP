#ifndef FIRST_H
#define FIRST_H
#include <iostream>
using namespace std;
class Second;
class First {
private:
	int M;
public:
	friend int f(First&, Second&);
	First(int n);
};
#endif
