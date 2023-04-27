#include <iostream>

int main()
{
	std::cout << "Size of an int: " << sizeof(int) << std::endl;
	std::cout << "Size of a long int: " << sizeof(long int) << std::endl;
	std::cout << "Size of an unsigned int: " << sizeof(unsigned int) << std::endl;
	std::cout << "Size of an unsigned long int: " << sizeof(unsigned long int) << std::endl;
	std::cout << "Size of a char: " << sizeof(char) << std::endl;
	std::cout << "Size of an unsigned char: " << sizeof(unsigned char) << std::endl;
	std::cout << "Size of a float: " << sizeof(float) << std::endl;
	std::cout << "Size of a double: " << sizeof(double) << std::endl;
	std::cout << "Size of a long double: " << sizeof(long double) << std::endl;
	std::cout << "Size of a boolean: " << sizeof(bool) << std::endl;

	return 0;
}