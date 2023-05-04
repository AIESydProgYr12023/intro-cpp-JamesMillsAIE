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
	static const int NUMBERS_COUNT = 10;
	int m_numbers[NUMBERS_COUNT] = { 0 };

};

