#include "GlobalFunctions.h"

#include <iostream>

void GetFibonacciNumbers(int _number, vector<int>& _result)
{
	// Exit the recursive loop when _number <= 0
	if (_number <= 0)
		return;

	// Ensure results has the first two values (0, 1)
	if (_result.size() < 2)
	{
		if (_number >= 1)
			_result.push_back(0);
		if (_number >= 2)
			_result.push_back(1);

		GetFibonacciNumbers(_number - 2, _result);
	}
	else
	{
		// Add the last two numbers
		int lastIndex = _result.size() - 1;
		int newNumber = _result[lastIndex] + _result[lastIndex - 1];

		// push the new number and repeat
		_result.push_back(newNumber);
		GetFibonacciNumbers(_number - 1, _result);
	}
}

void PrintFibonacciSequence(int _count)
{
	vector<int> sequence;
	GetFibonacciNumbers(_count, sequence);

	for (int i = 0; i < sequence.size(); i++)
	{
		std::cout << sequence[i] << ", ";
	}
}