#include <iostream>
#include <string>
#include <exception>

using std::string;
using std::runtime_error;
using std::exception;

double Calculate(double _num1, double _num2, const string& _operation)
{
    if (_operation == "Add")
        return _num1 + _num2;
    
    if (_operation == "Sub")
        return _num1 - _num2;
    
    if (_operation == "Mul")
        return _num1 * _num2;

    if (_operation == "Div")
        return _num1 / _num2;

    // if our code here, than the operation was invalid
    // rather than returning a valid number, we will throw an exception
    // the developers calling this calculate with either have to validate
    // the operation input before calling, or catch the exception
    throw runtime_error("Invalid Operation: " + _operation);
}

int main()
{
    try
    {
        std::cout << Calculate(10, 20, "Add") << std::endl;
        std::cout << Calculate(10, 20, "Sub") << std::endl;
        std::cout << Calculate(10, 20, "Mul") << std::endl;
        std::cout << Calculate(10, 20, "Div") << std::endl;

        // what should your calculate function do for an invalid operator?
        std::cout << Calculate(10, 20, "BANANA") << std::endl;
    }
    catch (exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}