#ifndef CLASS2_H
#define CLASS2_H
#include "Class1.h"
#include <string>
using namespace std;
class Class2:public Class1
{
private:
	string Object_Name;
public:
	Class2(string Object_Name);
	string name_getter();
};
#endif
