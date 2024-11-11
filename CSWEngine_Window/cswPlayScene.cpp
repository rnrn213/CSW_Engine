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
#include "cswPlayerScript.h"
#include "cswCamera.h"
#include "cswRenderer.h"

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
			// main camera
			GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			renderer::mainCamera = cameraComp;

			mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
			SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
			sr->SetSize(Vector2(3.0f, 3.0f));
			mPlayer->AddComponent<PlayerScript>();

			graphics::Texture* packmanTexture = Resources::Find<graphics::Texture>(L"PackMan");
			sr->SetTexture(packmanTexture);

			GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::BackGround);
			SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
			bgSr->SetSize(Vector2(3.0f, 3.0f));

			graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Map");
			bgSr->SetTexture(bgTexture);

			// 게임 오브젝트 생성 후에 레이어와 게임오브젝트들의 initialize 함수를 호출
			Scene::Initialize();
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
		//wchar_t str[50] = L"Play Scene";
		//TextOut(hdc, 0, 0, str, 10);
	}
	void PlayScene::OnEnter()
	{
		Scene::OnEnter();
	}
	void PlayScene::OnExit()
	{
		Scene::OnExit();
	}
}
