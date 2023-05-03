#pragma once

#include <string>

using std::string;

class Application
{
public:
	Application();
	~Application();

	void Run();

private:
	static const int NUM_DRAGONS = 3;
	static const int NUM_DAYS = 7;

	// Array of dragon names
	// will be populated at runtime via console input
	string m_dragons[NUM_DRAGONS];

	// Array of days in week
	string m_days[NUM_DAYS] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

	// 2D array of amount of food eaten per day by a dragon.
	// row: food data for the given dragon
	// col: food eaten on a give day
	int m_foodEaten[NUM_DRAGONS][NUM_DAYS];

	// total food eaten for each dragon at the end of the week
	int m_totalFoodEaten[NUM_DRAGONS];

private:
	// Populates m_foodEaten with random values
	void GenerateFoodEatenData();

	// Requests console input for user to enter names of dragons
	void PromptDragonNames();

	// Output to console the food each dragon ate each day
	void PrintDragonFoodTable();

	// Prints any additional information (such as the dragon who ate the most and least food)
	void PrintExtraReport();

};

