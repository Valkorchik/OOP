#ifndef CLASS3_H
#define CLASS3_H
#include "Class1.h"
#include <string>
using namespace std;
class Class3:public Class1
{
private:
	string Object_Name;
public:
	Class3(string Object_Name);
	string name_getter();
};
#endif
