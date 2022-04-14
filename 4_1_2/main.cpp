#include <iostream>
#include "Class1.h"
#include "Class2.h"
#include "Class3.h"
#include "Class4.h"
int main()
{
	string Object_Name;
	int Value;
	cin>>Object_Name>>Value;
	Class4 obj(Object_Name,Value);
	return 0;
}
