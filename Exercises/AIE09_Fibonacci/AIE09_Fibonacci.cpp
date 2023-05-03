#include <iostream>
#include <vector>

using std::vector;

vector<int> GetFibonacciSequence(int _count);

int main()
{
    vector<int> sequence = GetFibonacciSequence(10);

    for (int i = 0; i < sequence.size(); i++)
        std::cout << sequence[i] << ", ";

    return 0;
}

vector<int> GetFibonacciSequence(int _count)
{
    vector<int> result;

    if (_count >= 1)
        result.push_back(0);

    if (_count >= 2)
        result.push_back(1);

    for (int i = 2; i < _count; i++)
    {
        result.push_back(result[i - 1] + result[i - 2]);
    }

    return result;
}