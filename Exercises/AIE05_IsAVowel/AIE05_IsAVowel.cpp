#include <iostream>

bool IsAVowel(char _character)
{
	return _character == 'A' || _character == 'E' || _character == 'I' || _character == 'O' || _character == 'U' ||
		_character == 'a' || _character == 'e' || _character == 'i' || _character == 'o' || _character == 'u';
}

int main()
{
	// These will output true
	std::cout << "A: " << IsAVowel('A') << std::endl;
	std::cout << "e: " << IsAVowel('e') << std::endl;
	std::cout << "I: " << IsAVowel('I') << std::endl;
	std::cout << "o: " << IsAVowel('o') << std::endl;
	std::cout << "U: " << IsAVowel('U') << std::endl;

	// These will output false
	std::cout << "1: " << IsAVowel('1') << std::endl;
	std::cout << ",: " << IsAVowel(',') << std::endl;
	std::cout << "z: " << IsAVowel('z') << std::endl;

	return 0;
}
