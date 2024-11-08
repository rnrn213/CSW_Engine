#pragma once
#include "../CSWEngine_SOURCE/cswSceneManager.h"
#include "cswPlayScene.h"

namespace csw
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");


		SceneManager::LoadScene(L"PlayScene");
	}
}