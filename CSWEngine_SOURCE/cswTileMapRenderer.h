#pragma once
#include "cswEntity.h"
#include "cswComponent.h"
#include "cswTexture.h"

namespace csw
{
	class TileMapRenderer : public Component
	{
	public:
		TileMapRenderer();
		~TileMapRenderer();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetTexture(graphics::Texture* texture) { mTexture = texture; }
		void SetSize(math::Vector2 size) { mSize = size; }

	private:
		Vector2 mTileSize;
		graphics::Texture* mTexture;
		Vector2 mSize;
		Vector2 mIndex;
	};
}

