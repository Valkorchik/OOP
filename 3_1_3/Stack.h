#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <iomanip>
using namespace std;
class Stack
{
private:
	int count;
	int* arr;

public:
	int size;
	string name;
	Stack(string name, int size);
	bool input(int element);
	bool output(int& trash);
	int count_elems();
};
#endif
