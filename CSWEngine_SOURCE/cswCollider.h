#pragma once
#include "cswComponent.h"

namespace csw
{
	class Collider : public Component
	{
	public:
		Collider(enums::eColliderType type);
		~Collider();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		Vector2 GetOffset() { return mOffset; }
		void SetOffset(Vector2 offset) { mOffset = offset; }
		UINT32 GetID() { return mID; }
		Vector2 GetSize() { return mSize; }
		void SetSize(Vector2 size) { mSize = size; }
		enums::eColliderType GetColliderType() { return mType; }

	private:
		static UINT32 mCollisionID;
		UINT mID;
		Vector2 mOffset;
		Vector2 mSize;
		enums::eColliderType mType;
	};
}

