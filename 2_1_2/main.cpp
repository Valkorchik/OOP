#include "Triangle.h"
#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	Triangle obj(a,b,c);
	cout<<"P = "<<obj.P()<<"\n";
	cout<<"S = "<<obj.S();
	return 0;
}