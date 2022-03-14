#ifndef SECOND_H
#define SECOND_H
class First;
class Second
{
private:
	int M1,M2;
public:
	friend int f(First&, Second&);
	void Sign(int&, int&);
};
#endif
