#include "Binary.h"
#include <iostream>

Binary::Binary(uint8_t value, uint8_t pattern)
{
	this->value = value;
	this->pattern = pattern;
}

Binary Binary::operator&=(Binary& other)
{
	return Binary(value = value & (other.value & ~(pattern & other.pattern)), pattern);
}

Binary Binary::operator|=(Binary& other)
{
	return Binary(value = value | (other.value & (pattern & other.pattern)), pattern);
}

void Binary::Output()
{
	if (value < 16)
		std::cout << '0';
	std::cout << std::hex << std::uppercase << (int)value;
}
