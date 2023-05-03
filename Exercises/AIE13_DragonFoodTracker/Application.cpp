#include "Application.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

Application::Application()
{

}

Application::~Application()
{

}

void Application::Run()
{
	// seed random so we get unique dragon food values every time
	srand(time(nullptr));

	PromptDragonNames();
	GenerateFoodEatenData();
	PrintDragonFoodTable();
	PrintExtraReport();
}

void Application::GenerateFoodEatenData()
{

}

void Application::PromptDragonNames()
{

}

void Application::PrintDragonFoodTable()
{

}

void Application::PrintExtraReport()
{

}