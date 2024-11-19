#pragma once
#include "../CSWEngine_SOURCE/cswSceneManager.h"
#include "cswPlayScene.h"
#include "cswTitleScene.h"
#include "cswToolScene.h"

namespace csw
{
	void LoadScenes()
	{
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");
		//SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::CreateScene<ToolScene>(L"ToolScene");

		SceneManager::LoadScene(L"ToolScene");
	}
}