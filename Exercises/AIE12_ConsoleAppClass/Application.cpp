#include "Application.h"

#include <iostream>

Application::Application(string _message) 
	: m_message(_message)
{
	
}

Application::~Application()
{

}

void Application::Run()
{
	PrintMessage();
}

void Application::PrintMessage()
{
	std::cout << m_message << std::endl;
}