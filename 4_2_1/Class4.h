#ifndef CLASS4_H
#define CLASS4_H
#include "Class1.h"
#include <string>
using namespace std;
class Class4:public Class1
{
private:
	string Object_Name;
public:
	Class4(string Object_Name);
	string name_getter();
};
#endif
