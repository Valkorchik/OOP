#ifndef CLASS5_H
#define CLASS5_H
#include "Class1.h"
#include <string>
using namespace std;
class Class5:public Class1
{
private:
	string Object_Name;
public:
	Class5(string Object_Name);
	string name_getter();
};
#endif
