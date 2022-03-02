#include "Number.h"
int main()
{
	int n, arr[10];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	Number obj(n);
	obj.CountN(arr);
	cout<<endl;
	obj.InverseN(arr);
	obj.CountN(arr);
	return 0;
}
