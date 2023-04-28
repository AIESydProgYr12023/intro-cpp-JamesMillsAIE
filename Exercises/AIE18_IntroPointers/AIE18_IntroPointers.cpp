#include <iostream>

void PrintNumber(int _num)
{
	std::cout << "Value is: " << _num << std::endl;
}

int main()
{
	int someValue = 5;

	PrintNumber(someValue);

	// * means pointer in this case
	// & gives the memory address of the variable
	int* someValuePtr = &someValue;

	// * in this case means to 'dereference' the pointer
	// giving the actual value of it
	PrintNumber(*someValuePtr);

	int someOtherValue = 6;
	someValuePtr = &someOtherValue;

	PrintNumber(*someValuePtr);

	int* someOtherPtr = someValuePtr;

	PrintNumber(*someOtherPtr);

	*someValuePtr = 17;

	PrintNumber(*someValuePtr);
	PrintNumber(*someOtherPtr);

	return 0;
}