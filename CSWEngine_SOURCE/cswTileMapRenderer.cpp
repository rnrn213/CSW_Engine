#include "cswTileMapRenderer.h"
#include "cswGameObject.h"
#include "cswTransform.h"
#include "cswTexture.h"
#include "cswRenderer.h"

namespace csw
{
	TileMapRenderer::TileMapRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(3.0f, 3.0f)
		, mIndex(8, 7)
		, mTileSize(16.0f, 16.0f)
	{
	}

	TileMapRenderer::~TileMapRenderer()
	{
	}

	void TileMapRenderer::Initialize()
	{
	}

	void TileMapRenderer::Update()
	{
	}

	void TileMapRenderer::LateUpdate()
	{
	}

	void TileMapRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		pos = renderer::mainCamera->CalculatePosition(pos);
		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			if (mTexture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(hdc
					, pos.x
					, pos.y
					, mTileSize.x * mSize.x * scale.x
					, mTileSize.y * mSize.y * scale.y
					, mTexture->GetHdc()
					, mIndex.x * mTileSize.x
					, mIndex.y * mTileSize.y
					, mTileSize.x
					, mTileSize.y
					, func);
			}
			else
			{
				TransparentBlt(hdc
					, pos.x
					, pos.y
					, mTileSize.x * mSize.x * scale.x
					, mTileSize.y * mSize.y * scale.y
					, mTexture->GetHdc()
					, mIndex.x * mTileSize.x
					, mIndex.y * mTileSize.y
					, mTileSize.x
					, mTileSize.y
					, RGB(255, 0, 255));
			}
		}
		//else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png)
		//{
		//	Gdiplus::Graphics graphics(hdc);

		//	graphics.TranslateTransform(pos.x, pos.y);
		//	graphics.RotateTransform(rot);
		//	graphics.TranslateTransform(-pos.x, -pos.y);

		//	graphics.DrawImage(mTexture->GetImage()
		//		, Gdiplus::Rect
		//		(
		//			pos.x, pos.y
		//			, mTexture->GetWidth() * mSize.x * scale.x
		//			, mTexture->GetHeight() * mSize.y * scale.y
		//		)
		//	);
		//}
	}
}