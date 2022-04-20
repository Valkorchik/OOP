#include "Class3.h"
#include <iostream>
#include <iomanip>
void Class3::in_out()
{
	Class::in_out();
	std::cout<<"Array dimension: "<<size<<std::endl;
	std::cout<<"The original array:";
	for(int i=0;i<size;i++)
	{
		std::cout<<std::setw(5)<<arr[i];
	}
	std::cout<<"\nMin: "<<Class1::func();
	std::cout<<"\nSum: "<<Class2::func();
}
