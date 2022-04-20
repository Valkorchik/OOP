#include <iostream>
#include "Class4.h"
int main()
{
	Class4* obj;
	int a1, a2, a3, a4;
	int x;
	std::cin >> a1 >> a2 >> a3 >> a4;
	obj = new Class4(a1, a2, a3, a4);
	std::cout << "a1 = " << a1 << "    a2 = " << a2 << "    a3 = " << a3 << "    a4 = " << a4;
	while (true)
	{
		std::cin >> x;
		if (x == 0)
			break;
		int class_name, num = 0;
		std::cin >> class_name;
		switch (class_name)
		{
			case 1:
				num = (obj)->Class1::Calculation(x);
				break;
			case 2:
				num = (obj)->Class2::Calculation(x);
				break;
			case 3:
				num = (obj)->Class3::Calculation(x);
				break;
			case 4:
				num = (obj)->Class4::Calculation(x);
				break;
			default:
				break;
		}
		std::cout << std::endl <<"Class "<<class_name<<"    "<< "F( " << x << " ) = " << num;
	}
	return 0;
}