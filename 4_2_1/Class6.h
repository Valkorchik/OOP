#ifndef CLASS6_H
#define CLASS6_H
#include "Class2.h"
#include "Class3.h"
#include <string>
using namespace std;
class Class6:public Class2,public Class3
{
private:
	string Object_Name;
public:
	Class6(string Object_Name);
	string name_getter();
};
#endif
