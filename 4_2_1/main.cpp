#include <iostream>
#include "Class8.h"
int main()
{
	Class8* p;
	std::string name;
	std::cin>>name;
	Class8 obj(name);
	p=&obj;
	std::cout<<((Class1*)(Class2*)p)->name_getter()<<std::endl;
	std::cout<<((Class1*)(Class3*)p)->name_getter()<<std::endl;
	std::cout<<((Class1*)(Class4*)p)->name_getter()<<std::endl;
	std::cout<<((Class2*)p)->name_getter()<<std::endl;
	std::cout<<((Class3*)p)->name_getter()<<std::endl;
	std::cout<<((Class4*)p)->name_getter()<<std::endl;
	std::cout<<((Class5*)p)->name_getter()<<std::endl;
	std::cout<<((Class6*)p)->name_getter()<<std::endl;
	std::cout<<((Class7*)p)->name_getter()<<std::endl;
	std::cout<<p->name_getter();
	return 0;
}
