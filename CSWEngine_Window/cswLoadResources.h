#pragma once
#include "../CSWEngine_SOURCE/cswResources.h"
#include "../CSWEngine_SOURCE/cswTexture.h"

namespace csw
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Chicken", L"..\\Resources\\chicken.bmp");
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
		Resources::Load<graphics::Texture>(L"MapleEffect", L"..\\Resources\\ezgif.com-gif-maker.png");
		Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\Player.bmp");
	}
}