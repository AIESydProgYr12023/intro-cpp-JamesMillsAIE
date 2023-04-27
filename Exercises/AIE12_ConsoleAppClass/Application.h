#pragma once

#include <string>

using std::string;

class Application
{
public:
	Application(string _message);
	~Application();

	void Run();

private:
	string m_message = "Hello World!";

	void PrintMessage();

};