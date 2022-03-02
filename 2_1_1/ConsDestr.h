#ifndef CONSDESTR_H
#define CONSDESTR_H
#include <iostream>
using namespace std;
class ConsDestr
{
public:
	ConsDestr()
	{
		cout<<"Constructor"<<endl;
	}
	~ConsDestr()
	{
		cout<<"Destructor";
	}
};
#endif
