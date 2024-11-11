#include "cswPlayScene.h"
#include "cswGameObject.h"
#include "cswPlayer.h"
#include "cswTransform.h"
#include "cswSpriteRenderer.h"
#include "cswInput.h"
#include "cswTitleScene.h"
#include "cswSceneManager.h"
#include "cswObject.h"
#include "cswTexture.h"
#include "cswResources.h"

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
			// ���� ������Ʈ�� ����� ���� ���ҽ��� ���� Load�صθ� ����.
			bg = object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));
			SpriteRenderer* sr
				= bg->AddComponent<SpriteRenderer>();
			
			graphics::Texture* bg = Resources::Find<graphics::Texture>(L"BG");
			sr->SetTexture(bg);

			// ���� ������Ʈ ���� �Ŀ� ���̾�� ���ӿ�����Ʈ���� initialize �Լ��� ȣ��
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
		tr->SetPosition(Vector2(0, 0));
	}
}
