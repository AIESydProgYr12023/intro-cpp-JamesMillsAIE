#include <iostream>

int StringLength(const char* _str);

int main()
{
	std::cout << "Length: " << StringLength("Banana") << std::endl;
	std::cout << "Length: " << StringLength("Apple") << std::endl;
	std::cout << "Length: " << StringLength("Mango") << std::endl;
	// Cause he's also a fruit (so squeezable)
	std::cout << "Length: " << StringLength("Attila") << std::endl;

	return 0;
}

int StringLength(const char* _str)
{
	// this will index into our string array
	int count = 0;

	// increment the count until we reach the null terminator
	while (_str[count] != '\0')
		count++;

	// count now represents how many items are in the string
	return count;
}