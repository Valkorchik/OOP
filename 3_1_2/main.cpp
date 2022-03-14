#include "First.h"
#include "Second.h"
int f(First& A, Second& B)
{
	int max=A.M;
	if (A.M >B.M2 && A.M>B.M1) max=A.M;
	if (B.M1>B.M2 && B.M1>A.M) max=B.M1;
	if (B.M2>B.M1 && B.M2>A.M) max=B.M2;
	cout << "max = " << max;
}
int main()
{
	int n, m1, m2;
	cin>>n;
	First A(n);
	cin>>m1>>m2;
	Second B;
	B.Sign(m1,m2);
	f(A,B);
}