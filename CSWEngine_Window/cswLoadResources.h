#pragma once
#include "../CSWEngine_SOURCE/cswResources.h"
#include "../CSWEngine_SOURCE/cswTexture.h"

namespace csw
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"C:\\Users\\rnrn2\\Downloads\\pic1.png");
	}
}