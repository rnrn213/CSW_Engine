#include "cswPlayScene.h"
#include "cswGameObject.h"
#include "cswPlayer.h"
#include "cswTransform.h"
#include "cswSpriteRenderer.h"
#include "cswInput.h"
#include "cswTitleScene.h"
#include "cswSceneManager.h"

namespace csw
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		{
			bg = new Player();
			Transform* tr
				= bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"C:\\Users\\rnrn2\\Downloads\\pic1.png");

			AddGameObject(bg, eLayerType::BackGround);
		}
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}
	void PlayScene::OnEnter()
	{
		Scene::OnEnter();
	}
	void PlayScene::OnExit()
	{
		Scene::OnExit();
		Transform* tr
			= bg->GetComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
	}
}
