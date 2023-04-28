#include "Application.h"

#include "GameObject.h"

#include <raylib.h>

Application::Application(int _width, int _height, const char* _title)
	: m_width(_width), m_height(_height), m_title(_title), m_player(new GameObject())
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
	m_player->Draw();
}

void Application::Update(float _dt)
{
	m_player->Update(_dt);
}