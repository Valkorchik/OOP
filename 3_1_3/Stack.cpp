#include "Stack.h"
Stack::Stack(string name, int size)
{
	this->name=name;
	this->size=size;
	this->arr=new int[size];
	count=0;
}
bool Stack::input(int element)
{
	if(count+1>size) return false;
	arr[count]=element;
	count++;
	return true;
}
bool Stack::output(int& trash)
{
	if(count-1<0) return false;
	count--;
	trash=arr[count];
	return true;
}
int Stack::count_elems()
{
	return count;
}

