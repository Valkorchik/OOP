#ifndef CLASS7_H
#define CLASS7_H
#include "Class4.h"
#include "Class5.h"
#include <string>
using namespace std;
class Class7:private Class4,private Class5
{
private:
	string Object_Name;
public:
	Class7(string Object_Name);
	string name_getter();
};
#endif
