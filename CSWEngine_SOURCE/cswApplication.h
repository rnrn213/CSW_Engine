#pragma once
#include "CommonInclude.h"
#include "cswGameObject.h"

namespace csw
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		GameObject mPlayer;
	};
}
