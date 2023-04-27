#include <iostream>
#include <string>

using std::string;

int main()
{
	std::cout << "Hello World!\n";
	std::cout << "Hello World!" << std::endl;
	std::cout << "Hello\tWorld!" << std::endl;

	const char* text = "Hello World!";
	std::cout << text << std::endl;

	string str = "Hello World!";
	std::cout << str << std::endl;

	return 0;
}