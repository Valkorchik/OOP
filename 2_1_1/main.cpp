#include <iostream>
using namespace std;
class ConsDestr
{
public:
	ConsDestr()
	{
		cout<<"Первая строка, с первой позиции: Constructor"<<endl;
	}
	~ConsDestr()
	{
		cout<<"Вторая строка, с первой позиции: Destructor";
	}
};
int main()
{
	ConsDestr obj;

}
