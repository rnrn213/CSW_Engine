#pragma once
#include "cswEntity.h"
#include "cswGameObject.h"
#include "cswLayer.h"

namespace csw 
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, const eLayerType type);

	private:
		std::vector<Layer*> mLayers;
	};
}

