#include "fbpch.h"
#include "Scene.h"
#include <Entity\Component\Transform.h>

namespace Fireblast
{
	std::shared_ptr<Scene> Scene::s_currentScene(nullptr);

	Scene::Scene()
		: m_Entities() {}

	Scene::~Scene()
	{
	}

	void Scene::LoadScene(std::shared_ptr<Scene> scene)
	{
		Scene::s_currentScene = scene;
		Scene::s_currentScene->Start();
	}

	void Scene::SpawnEntity(Entity* entity)
	{
		m_Entities.push_back(entity);
		entity->Start();
	}

	void Scene::SpawnEntity(Entity* entity, glm::vec3 pos)
	{
		SpawnEntity(entity);
		entity->GetComponent<Transform>()->SetPosition(pos);
	}

	void Scene::Start()
	{
		OnStart();
	}

	void Scene::Update()
	{
		OnUpdate();

		for (unsigned int i = 0; i < m_Entities.size(); i++)
		{
			m_Entities[i]->Update();
		}
	}

}