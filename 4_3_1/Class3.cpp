#include "Class3.h"
#include <iostream>
void Class3::Executor()
{
	Class1::Input();
	std::cout<<"Array dimension: "<<size<<std::endl;
	std::cout<<"The original array:";
	Class2::Output();
	Class2::Sort();
	std::cout<<std::endl<<"An ordered array:";
	Class2::Output();
}
