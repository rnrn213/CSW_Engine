#pragma once
#include "../CSWEngine_SOURCE/cswResources.h"
#include "../CSWEngine_SOURCE/cswTexture.h"

namespace csw
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Map", L"..\\Resources\\img\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"PackMan", L"..\\Resources\\img\\pacman\\0.png");
		Resources::Load<graphics::Texture>(L"TitleBackground", L"..\\Resources\\PalmOS - Tetris Classic - Gui.png");
		Resources::Load<graphics::Texture>(L"Chicken", L"..\\Resources\\chicken.bmp");
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
	}
}