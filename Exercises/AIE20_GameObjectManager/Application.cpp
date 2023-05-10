#include "Application.h"

#include "GameObjectManager.h"
#include "Player.h"

#include <raylib.h>

GameObjectManager* Application::m_goManager = nullptr;

Player* player = nullptr;

GameObjectManager* Application::GetGOManager()
{
	return m_goManager;
}

Application::Application(int _width, int _height, const char* _title)
	: m_width(_width), m_height(_height), m_title(_title)
{

}

void Application::Run()
{
	InitWindow(m_width, m_height, m_title);
	SetTargetFPS(60);

	m_goManager = new GameObjectManager();

	Load();

	while (!WindowShouldClose())
	{
		Update(GetFrameTime());

		BeginDrawing();
		ClearBackground(RAYWHITE);

		Draw();

		EndDrawing();
	}

	Unload();

	delete m_goManager;
	m_goManager = nullptr;

	CloseWindow();
}

void Application::Draw()
{
	m_goManager->Draw();
}

void Application::Update(float _dt)
{
	m_goManager->Update(_dt);
}

void Application::Load()
{
	player = new Player({ 400, 300 });
	m_goManager->AddObject(player);
}

void Application::Unload()
{
	m_goManager->RemoveObject(player);
	player = nullptr;
}