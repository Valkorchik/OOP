#include "Operation.h"
int main()
{
	int first, second, i = 0;
	char operation;
	Operation obj;
	cin >> first >> operation >> second;
	obj.FirstResult(first, operation, second);
	cin >> operation >> second;
	obj.SecondResult(second, operation);
	cin >> operation >> second;	obj.SecondResult(second, operation);
	obj.FirstResultCout();
	while (true)
	{
		i++;
		cin >> operation;
		if (operation == 'C')
		{
			break;
		}
		cin >> second;
		obj.SecondResult(second, operation);
		if (i % 3 == 0)
		{
			obj.SecondResultCout();
		}
	}
}