#include "Application.h"

#include <iostream>
#include <fstream>

using std::fstream;
using std::ios;

void Application::Run()
{
	const char* filename = "data.txt";

	srand(time(nullptr));

	m_num1 = rand() % 1000;
	m_num2 = rand() % 1000;
	m_num3 = rand() % 1000;
	m_num4 = rand() % 1000;
	m_num5 = rand() % 1000;
	m_num6 = rand() % 1000;

	SaveToFile(filename);

	// Reset the numbers
	m_num1 = 0;
	m_num2 = 0;
	m_num3 = 0;
	m_num4 = 0;
	m_num5 = 0;
	m_num6 = 0;

	// Load the numbers back in
	LoadFromFile(filename);

	std::cout << m_num1 << std::endl;
	std::cout << m_num2 << std::endl;
	std::cout << m_num3 << std::endl;
	std::cout << m_num4 << std::endl;
	std::cout << m_num5 << std::endl;
	std::cout << m_num6 << std::endl;
}

void Application::SaveToFile(const char* _filename)
{
	// Open the file
	fstream file;
	file.open(_filename, ios::out);

	// Check if the file successfully opened
	if (file.is_open())
	{
		// Write each number
		file << m_num1 << std::endl;
		file << m_num2 << std::endl;
		file << m_num3 << std::endl;
		file << m_num4 << std::endl;
		file << m_num5 << std::endl;
		file << m_num6 << std::endl;
	}

	// close the file
	file.close();
}

void Application::LoadFromFile(const char* _filename)
{
	// Open the file
	fstream file;
	file.open(_filename, ios::in);

	// Check if the file successfully opened
	if (file.is_open())
	{
		// Read each number
		file >> m_num1;
		file >> m_num2;
		file >> m_num3;
		file >> m_num4;
		file >> m_num5;
		file >> m_num6;
	}

	// close the file
	file.close();
}