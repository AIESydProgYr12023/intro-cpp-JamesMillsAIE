#include <iostream>
#include <string>

const int* BinarySearch(const int* _arr, int _count, int _searchVal);
void TestResult(const int* _result, int* const _expected);

int main()
{
	const int NUM_ITEMS = 8;
	int arr1[NUM_ITEMS] = { 1, 3, 5, 7, 9, 11, 13, 15 };

	// The numbers in the array are assumed to be sorted
	// search for the values 9, 1, 15, 0

	TestResult( BinarySearch(arr1, NUM_ITEMS, 9),  &arr1[4]   );
	TestResult( BinarySearch(arr1, NUM_ITEMS, 1),  &arr1[0]   );
	TestResult( BinarySearch(arr1, NUM_ITEMS, 15), &arr1[7]   );
	TestResult( BinarySearch(arr1, NUM_ITEMS, 0),  nullptr    );
	TestResult( BinarySearch(arr1, NUM_ITEMS, 16), nullptr    );

	return 0;
}

void TestResult(const int* _result, int* const _expected)
{
	if (_result == _expected)
	{
		std::cout << "PASS: result(" <<
			(_result == nullptr ? "nullptr" : std::to_string(*_result).c_str()) << ")" << std::endl;
		return;
	}

	std::cout << "FAIL: received(" <<
		(_result == nullptr ? "nullptr" : std::to_string(*_result).c_str()) << ") expected(" <<
		(_expected == nullptr ? "nullptr" : std::to_string(*_expected).c_str()) << ")" << std::endl;
}

const int* BinarySearch(const int* _arr, int _count, int _searchVal)
{
	// TODO: Implement a binary search
	// the array is assumed to be sorted

	// This method should:
	//	- Return: nullptr if the value is not found
	//  - Return: pointer to the found value in the array

	return nullptr;
}