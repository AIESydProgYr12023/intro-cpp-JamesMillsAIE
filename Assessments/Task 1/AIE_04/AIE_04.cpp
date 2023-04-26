#include <iostream>

void SortArray(int* _arr, int _count);
bool IsArraySorted(const int* _arr, int _count);

int main()
{
	const int NUM_ITEMS = 8;
	int numbers[NUM_ITEMS] = { 13, 1, 7, 5, 11, 9, 15, 3 };

	SortArray(numbers, NUM_ITEMS);

	// Test: all values should be sorted in ascending order
	if (IsArraySorted(numbers, NUM_ITEMS)) std::cout << "Pass: the array is sorted" << std::endl;
	else std::cout << "Fail: the array is not sorted" << std::endl;

	return 0;
}

bool IsArraySorted(const int* _arr, int _count)
{	
	for (int i = 0; i < _count - 1; i++)
	{
		if (_arr[i] > _arr[i + 1])
			return false;
	}

	return true;
}


void SortArray(int* _arr, int _count)
{
	// TODO: 
	// modify the values in the array so that when this method returns
	// all values are sorted in ascending order
}
