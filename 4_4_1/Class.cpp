#include "Class.h"
#include <iostream>
void Class::in_out()
{
	std::cin>>size;
	arr=new int[size];
	for(int i=0;i<size;i++)
	{
		std::cin>>arr[i];
	}
}