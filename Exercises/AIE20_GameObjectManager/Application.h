#pragma once

class GameObjectManager;

class Application
{
public:
	static GameObjectManager* GetGOManager();

	Application(int _width, int _height, const char* _title);

	void Run();
	void Draw();
	void Update(float _dt);

	void Load();
	void Unload();

private:
	static GameObjectManager* m_goManager;

	int m_width;
	int m_height;
	const char* m_title;

};

