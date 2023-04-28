#pragma once

class Application
{
public:
	Application(int _width, int _height, const char* _title);

	void Run();
	void Draw();
	void Update(float _dt);

private:
	int m_width;
	int m_height;
	const char* m_title;

};

