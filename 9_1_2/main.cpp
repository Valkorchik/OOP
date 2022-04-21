#include <iostream>
#include "Binary.h"
#include <vector>

int main() {
	int a, b, n;
	char sign;
	std::vector<Binary> obj;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int value, pattern;
		std::cin >> std::hex >> value >> pattern;
		obj.push_back(Binary(value, pattern));
	}

	while (std::cin >> a >> sign >> b) {
		switch (sign)
		{
			case '&':
				obj[a - 1] &= obj[b - 1];
				break;
			case '|':
				obj[a - 1] |= obj[b - 1];
				break;
			default:
				break;
		}
	}

	obj[a - 1].Output();
	return 0;
}