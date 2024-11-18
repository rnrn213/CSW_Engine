#include "cswTitleScene.h"
#include "cswInput.h"
#include "cswSceneManager.h"
#include "cswPlayScene.h"
#include "cswSpriteRenderer.h"
#include "cswObject.h"
#include "cswResources.h"
#include "CommonInclude.h"

namespace csw
{
	using namespace math;
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		//GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::BackGround);
		//SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		//bgSr->SetSize(Vector2(5.0f, 5.0f));

		//graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"TitleBackground");
		//bgSr->SetTexture(bgTexture);

		// 게임 오브젝트 생성 후에 레이어와 게임오브젝트들의 initialize 함수를 호출
		Scene::Initialize();
	}
	void TitleScene::Update()
	{
		Scene::Update();
	}
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		/*wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);*/
	}
	void TitleScene::OnEnter()
	{
		Scene::OnEnter();
	}
	void TitleScene::OnExit()
	{
		Scene::OnExit();
	}
}