#include "Class1.h"
int Class1::func()
{
	int value=arr[0];
	for(int i=1;i<size;i++)
	{
		value-=arr[i];
	}
	return value;
}