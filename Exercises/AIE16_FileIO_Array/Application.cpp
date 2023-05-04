#include "Application.h"

#include <iostream>
#include <fstream>

using std::fstream;
using std::ios;

void Application::Run()
{
	const char* filename = "data.dat";
	
	srand(time(nullptr));

	// Set all numbers to a random value
	for (int i = 0; i < NUMBERS_COUNT; i++)
	{
		m_numbers[i] = rand() % 100;
	}

	// Save the numbers to file
	SaveToFile(filename);

	// Reset the numbers
	for (int i = 0; i < NUMBERS_COUNT; i++)
	{
		m_numbers[i] = 0;
	}

	// Load the numbers
	LoadFromFile(filename);

	// Print to console
	for (int i = 0; i < NUMBERS_COUNT; i++)
	{
		std::cout << m_numbers[i] << std::endl;
	}
}

void Application::SaveToFile(const char* _filename)
{
	// Open the file
	fstream file;
	file.open(_filename, ios::out | ios::binary);

	// validate the file is open
	if (file.is_open())
	{
		// Write all 10 numbers to the file
		file.write((char*)&m_numbers[0], sizeof(int) * NUMBERS_COUNT);
	}

	// close the file
	file.close();
}

void Application::LoadFromFile(const char* _filename)
{
	// Open the file
	fstream file;
	file.open(_filename, ios::in | ios::binary);

	// validate the file is open
	if (file.is_open())
	{
		// Write all 10 numbers to the file
		file.read((char*)&m_numbers[0], sizeof(int) * NUMBERS_COUNT);
	}

	// close the file
	file.close();
}