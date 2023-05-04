#include "Application.h"

#include <iostream>
#include <fstream>

using std::fstream;
using std::ios;

void Application::Run()
{
	const char* filename = "data.dat";

	srand(time(nullptr));

	// Randomly pick a number between 1 and 20 to be the size of our array
	m_numbersCount = (rand() % 20) + 1;

	// Create the array in memory
	m_numbers = new int[m_numbersCount];

	// Initialise each number with a random value
	for (int i = 0; i < m_numbersCount; i++)
	{
		m_numbers[i] = rand() % 100;
	}

	// Save the array to memory
	SaveToFile(filename);

	// Clear the array completely
	m_numbersCount = 0;
	delete[] m_numbers;

	// Load the numbers from the file and print them
	LoadFromFile(filename);

	for (int i = 0; i < m_numbersCount; i++)
	{
		std::cout << m_numbers[i] << std::endl;
	}
}

void Application::SaveToFile(const char* _filename)
{
	// Open the file
	fstream file;
	file.open(_filename, ios::out | ios::binary);

	// Validate the file is open
	if (file.is_open())
	{
		// Write the number count to the file
		file.write((char*)&m_numbersCount, sizeof(int));

		// Write the whole array to the file
		file.write((char*)&m_numbers[0], sizeof(int) * m_numbersCount);
	}

	// close the file
	file.close();
}

void Application::LoadFromFile(const char* _filename)
{
	// Open the file
	fstream file;
	file.open(_filename, ios::in | ios::binary);

	// Validate the file is open
	if (file.is_open())
	{
		// Read the first element which is the number array length
		file.read((char*)&m_numbersCount, sizeof(int));

		// Allocate the memory for the array
		m_numbers = new int[m_numbersCount];

		// Read the number array from file
		file.read((char*)&m_numbers[0], sizeof(int) * m_numbersCount);
	}

	// close the file
	file.close();
}