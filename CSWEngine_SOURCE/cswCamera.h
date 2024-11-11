#pragma once
#include "cswComponent.h"

namespace csw
{
	using namespace csw::math;
	class Camera : public Component
	{
	public:
		Vector2 CalculatePosition(Vector2 pos) { return pos - mDistance; }

		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		class GameObject* mTarget;
		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;
	};
}
