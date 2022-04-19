#include "Class1.h"
#include <iostream>
void Class1::Input()
{
	std::cin>>size;
	arr=new int[size];
	for(int i=0;i<size;i++)
	{
		std::cin>>arr[i];
	}
}