#ifndef _BINARY_H_
#define _BINARY_H_
#include <cstdint>
class Binary
{
private:
	unsigned char value;
	unsigned char pattern;
public:
	Binary(unsigned char value, unsigned char pattern);
	Binary operator &= (Binary& other);
	Binary operator |= (Binary& other);
	void Output();
};
#endif