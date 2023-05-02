#include <iostream>
#include <string>

using std::string;
using std::getline;

bool IsAVowel(char _character);
int CountVowels(string& _name);
string ToUpper(string& _name);
string ToLower(string& _name);
string FirstOnly(string& _name);
string LastOnly(string& _name);
string ReverseName(string& _name);

int main()
{
    string name;

    std::cout << "What is your name: " << std::endl;
    getline(std::cin, name);

    std::cout << "Hello " << name << std::endl;
    std::cout << "Your name is: " << name.size() << " characters long." << std::endl;
    std::cout << "There are " << CountVowels(name) << " vowels in your name." << std::endl;
    std::cout << "Upper: <" << ToUpper(name) << ">" << std::endl;
    std::cout << "Lower: <" << ToLower(name) << ">" << std::endl;
    std::cout << "First name only: <" << FirstOnly(name) << ">" << std::endl;
    std::cout << "Last name only: <" << LastOnly(name) << ">" << std::endl;
    std::cout << "Reversed: <" << ReverseName(name) << ">" << std::endl;

    return 0;
}