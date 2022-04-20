#include "Class2.h"
int Class2::func()
{
	int value=arr[0];
	for(int i=1;i<size;i++)
	{
		value+=arr[i];
	}
	return value;
}


