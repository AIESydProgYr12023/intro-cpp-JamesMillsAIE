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
	int m_num1 = 0;
	int m_num2 = 0;
	int m_num3 = 0;
	int m_num4 = 0;
	int m_num5 = 0;
	int m_num6 = 0;

};

