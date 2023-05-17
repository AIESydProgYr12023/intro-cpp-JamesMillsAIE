#include "Application.h"

#include "Config.h"

Application::Application()
	: m_applicationDir(nullptr)
{

}

void Application::Run(char* _argv[])
{
	BuildApplicationDir(_argv);
	Config::m_instance = new Config(m_applicationDir);
	Config::m_instance->Load();

	int width = *Config::Get<int>(WINDOW_CATEGORY, "width");
	int height = *Config::Get<int>(WINDOW_CATEGORY, "height");
	const char* title = Config::Get<string>(PROGRAM_CATEGORY, "name")->c_str();

	InitWindow(width, height, title);
	SetTargetFPS(60);

	SetExitKey(*Config::Get<int>(PROGRAM_CATEGORY, "quitKey"));

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

const char* Application::GetApplicationDir() const
{
	return m_applicationDir;
}

void Application::BuildApplicationDir(char* _argv[])
{
	string argvString = string(_argv[0]);
	string exeDir = argvString.substr(0, argvString.find_last_of('\\'));

	m_applicationDir = new char[exeDir.size()];
	strcpy(m_applicationDir, exeDir.c_str());
}
