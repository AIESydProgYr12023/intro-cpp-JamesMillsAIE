#pragma once

#include <list>
#include <vector>
#include <functional>

class GameObject;

using std::list;
using std::vector;
using std::function;

class GameObjectManager
{
public:
	void AddObject(GameObject* _obj);
	void RemoveObject(GameObject* _obj);

private:
	list<GameObject*> m_objects;
	int m_objectCount;

	vector<function<void()>> m_listModifications;

private:
	friend class Application;

	GameObjectManager();
	~GameObjectManager();

	void Update(float _dt);
	void Draw();

};