#pragma once
#include "../CSWEngine_SOURCE/cswSceneManager.h"
#include "cswPlayScene.h"
#include "cswTitleScene.h"

namespace csw
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");


		SceneManager::LoadScene(L"TitleScene");
	}
}