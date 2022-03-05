#include "Stack.h"
int main()
{
	string name;
	int size;
	cin>>name>>size;
	Stack obj1(name,size);
	cin>>name>>size;
	Stack obj2(name,size);
	int element;
	do
	{
		cin>>element;
	}
	while(obj1.input(element)&&obj2.input(element));
	cout<<obj1.name<<" "<<obj1.size<<endl;
	cout<<obj2.name<<" "<<obj2.size<<endl;
	cout<<left<<setw(15)<<obj1.name<<left<<setw(15)<<obj2.name;
	int elem1,elem2;
	obj1.output(elem1);
	while(true)
	{
		cout<<endl;
		if(obj2.output(elem2))
		{
			cout<<right<<setw(15)<<elem1;
		}
		else
		{
			cout<<right<<setw(15)<<elem1;
			break;
		}
		if(obj1.output(elem1))
		{
			cout<<right<<setw(15)<<elem2;
		}
		else
		{
			cout<<right<<setw(15)<<elem2;
			break;
		}
	}
	return 0;
}
