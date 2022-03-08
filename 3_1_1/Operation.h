#ifndef OPERATION_H
#define OPERATION_H
#include <iostream>
using namespace std;
class Operation
{
private:
	int number;
public:
	int FirstResult(int first, char op, int second);
	int SecondResult(int second,char op);
	int FirstResultCout();
	int SecondResultCout();
};
#endif
