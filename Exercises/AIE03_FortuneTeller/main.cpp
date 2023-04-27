#include <iostream>
#include <string>

using std::string;
using std::getline;

int main()
{
	int numOfChildren = 0;
	string partnersName = "";
	string geoLocation = "";
	string jobTitle = "";

	std::cout << "How many little yous do you want? ";
	std::cin >> numOfChildren;
	std::cin.ignore();

	std::cout << "\nWhat is your partner's name: ";
	getline(std::cin, partnersName);

	std::cout << "\nWhere for art thou: ";
	getline(std::cin, geoLocation);

	std::cout << "\nWhat do you doeth: ";
	getline(std::cin, jobTitle);

	std::cout << "You live in " << geoLocation <<
		", your job is " << jobTitle <<
		", your bae is " << partnersName << 
		" and you will have " << numOfChildren << " mini-me's." << std::endl;

	return 0;
}