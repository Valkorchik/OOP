#include "Number.h"
#include <iomanip>
Number::Number(int n1)
{
	n=n1;
	cout<<"N = "<<n<<endl;
}
int Number::CountN(int* arr)
{
	for(int i=0;i<n;i++)
	{
		cout <<right<<setw(5)<<arr[i];
	}
}
int Number::InverseN(int* arr)
{
	int temp;
	for(int i=0;i<n/2;i++)
	{
		temp=arr[i];
		arr[i]=arr[n-i-1];
		arr[n-i-1]=temp;
	}
}

