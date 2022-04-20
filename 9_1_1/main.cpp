#include <iostream>
#include "Triangle.h"
#include <vector>
int main() {
	int a, b, c, n;
	char sign;
	std::cin >> n;
	std::vector<Triangle> obj;
	for (int i = 0; i < n; i++) {
		std::cin >> a >> b >> c;
		obj.push_back(Triangle(a, b, c));
	}
	while (std::cin >> a >> sign >> b) {
		switch (sign)
		{
			case '+':
				obj[a - 1] = obj[a - 1] + obj[b - 1];
				break;
			case '-':
				obj[a - 1] = obj[a - 1] - obj[b - 1];
				break;
			default:
				break;
		}
	}
	obj[a-1].Output();
	return 0;
}
