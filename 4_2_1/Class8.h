#ifndef CLASS8_H
#define CLASS8_H
#include "Class6.h"
#include "Class7.h"
#include <string>
using namespace std;
class Class8:private Class6,private Class7
{
private:
	string Object_Name;
public:
	Class8(string Object_Name);
	string name_getter();
};
#endif
