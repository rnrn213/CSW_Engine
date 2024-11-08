#include "cswGameObject.h"
#include "cswInput.h"
#include "cswTime.h"

namespace csw
{
	GameObject::GameObject()
		: mX(0)
		, mY(0)
	{

	}
	GameObject::~GameObject()
	{

	}
	void GameObject::Update()
	{
		const int speed = 100.0f;
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::D))
		{
			mX += speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::W))
		{
			mY -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mY += speed * Time::DeltaTime();
		}
	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC hdc)
	{
		Rectangle(hdc, 500 + mX, 500 + mY, 600 + mX, 600 + mY);
	}
}