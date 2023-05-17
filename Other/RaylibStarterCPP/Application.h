#pragma once

class Application
{
public:
	Application();

	void Run(char* _argv[]);
	void Draw();
	void Update(float _dt);

	const char* GetApplicationDir() const;

private:
	void BuildApplicationDir(char* _argv[]);

private:
	char* m_applicationDir;

};

