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
#include "cswAnimator.h"
#include "cswCat.h"
#include "cswCatScript.h"
#include "cswBoxCollider2D.h"
#include "cswCollisionManager.h"

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
			CollisionManager::CollisionLayerCheck(enums::eLayerType::Player, enums::eLayerType::Animal, true);

			// main camera
			GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			renderer::mainCamera = cameraComp;

			mPlayer = object::Instantiate<Player>(enums::eLayerType::Particle);
			PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();
			BoxCollider2D* collider = mPlayer->AddComponent<BoxCollider2D>();
			collider->SetOffset(Vector2(-50.0f, -50.0f));

			graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"Player");
			Animator* playerAnimator = mPlayer->AddComponent<Animator>();
			playerAnimator->CreateAnimation(L"Idle", playerTex
				, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
			playerAnimator->CreateAnimation(L"FrontGiveWater", playerTex
				, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);

			playerAnimator->PlayAnimation(L"Idle", false);

			playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);

			mPlayer->GetComponent<Transform>()->SetPosition(Vector2(300.0f, 250.0f));
			//mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
			//mPlayer->GetComponent<Transform>()->SetRotation(0.0f);

			// CAT
			Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
			cat->AddComponent<CatScript>();

			////cameraComp->SetTarget(cat);

			////graphics::Texture* packmanTexture = Resources::Find<graphics::Texture>(L"MapleEffect");
			////Animator* animator = mPlayer->AddComponent<Animator>();
			////animator->CreateAnimation(L"CatFrontMove", packmanTexture
			////	, Vector2(0.0f, 0.0f), Vector2(386.0f, 246.0f), Vector2::Zero, 8, 0.1f);

			////animator->PlayAnimation(L"CatFrontMove");

			graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
			Animator* catAnimator = cat->AddComponent<Animator>();

			BoxCollider2D* boxCatCollider = cat->AddComponent<BoxCollider2D>();
			boxCatCollider->SetOffset(Vector2(-50.0f, -50.0f));


			////catAnimator->CreateAnimation(L"DownWalk", catTex
			////	, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			////catAnimator->CreateAnimation(L"RightWalk", catTex
			////	, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			////catAnimator->CreateAnimation(L"UpWalk", catTex
			////	, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			////catAnimator->CreateAnimation(L"LeftWalk", catTex
			////	, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			////catAnimator->CreateAnimation(L"SitDown", catTex
			////	, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			////catAnimator->CreateAnimation(L"Grooming", catTex
			////	, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			////catAnimator->CreateAnimation(L"LayDown", catTex
			////	, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

			////catAnimator->PlayAnimation(L"SitDown", false);

			catAnimator->CreateAnimationByFolder(L"MushroomIdle", L"..\\Resources\\Mushroom", Vector2::Zero, 0.1f);

			catAnimator->PlayAnimation(L"MushroomIdle", true);

			cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
			//cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
			//cat->GetComponent<Transform>()->SetRotation(0.0f);

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
