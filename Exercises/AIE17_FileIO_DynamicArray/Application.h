#pragma once

class Application
{
public:
	Application() = default;
	~Application() = default;

	void Run();

	void SaveToFile(const char* _filename);
	void LoadFromFile(const char* _filename);

private:
	// The length of the array in the file
	int m_numbersCount = 0;
	// The pointer to the memory of the array in RAM
	int* m_numbers = nullptr;

};

