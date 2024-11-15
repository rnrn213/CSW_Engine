#pragma once


namespace csw::enums
{
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Animator,
		Script,
		Camera,
		End,
	};
	enum class eLayerType
	{
		None,
		BackGround,
		// Tree
		// Character
		Player,
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End,
	};
}