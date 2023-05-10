#include "GameObjectManager.h"

#include "GameObject.h"

void GameObjectManager::AddObject(GameObject* _obj)
{
	m_listModifications.push_back([&, this]()
		{
			m_objects.push_back(_obj);
			_obj->Load();
			m_objectCount++;
		}
	);
}

void GameObjectManager::RemoveObject(GameObject* _obj)
{
	m_listModifications.push_back([&, this]()
		{
			auto iter = std::find(m_objects.begin(), m_objects.end(), _obj);
			if (iter != m_objects.end())
			{
				m_objects.remove(_obj);
				_obj->Unload();
				m_objectCount--;
				delete _obj;
			}
		}
	);
}

GameObjectManager::GameObjectManager()
	: m_objectCount(0)
{
}

GameObjectManager::~GameObjectManager()
{
	for (auto iter = m_objects.begin(); iter != m_objects.end(); iter++)
	{
		delete (*iter);
	}

	m_objects.clear();
	m_objectCount = 0;
	m_listModifications.clear();
}

void GameObjectManager::Update(float _dt)
{
	for (auto& update : m_listModifications)
		update();

	m_listModifications.clear();
 
	for (auto iter = m_objects.begin(); iter != m_objects.end(); iter++)
	{
		GameObject* go = *iter;
		if (go != nullptr)
			go->Update(_dt);
	}
}

void GameObjectManager::Draw()
{
	for (auto iter = m_objects.begin(); iter != m_objects.end(); iter++)
	{
		GameObject* go = *iter;
		if (go != nullptr)
			go->Draw();
	}
}
