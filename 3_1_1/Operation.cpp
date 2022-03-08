#include "Operation.h"

int Operation::FirstResult(int first, char op, int second)
{
	if(op=='+') number=first+second;
	if(op=='-') number=first-second;
	if(op=='*') number=first*second;
	if(op=='%') number=first%second;
}
int Operation::SecondResult(int second, char op)
{
	if(op=='+') number=number+second;
	if(op=='-') number=number-second;
	if(op=='*') number=number*second;
	if(op=='%') number=number%second;
}
int Operation::FirstResultCout()
{
	cout<<number;
}
int Operation::SecondResultCout()
{
	cout<<endl<<number;
}
