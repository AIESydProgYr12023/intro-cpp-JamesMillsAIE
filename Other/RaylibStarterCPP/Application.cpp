#include "Application.h"

#include <raylib.h>

Application::Application(int _width, int _height, const char* _title)
	: m_width(_width), m_height(_height), m_title(_title)
{

}

void Application::Run()
{
	InitWindow(m_width, m_height, m_title);
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		Update(GetFrameTime());

		BeginDrawing();
		ClearBackground(RAYWHITE);

		Draw();

		EndDrawing();
	}

	CloseWindow();
}

void Application::Draw()
{
	DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
}

void Application::Update(float _dt)
{

}