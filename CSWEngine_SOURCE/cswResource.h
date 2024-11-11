#pragma once
#include "cswEntity.h"

namespace csw
{
	class Resource abstract : public Entity // 추상 클래스 메모리 할당 x 상속받아서만 사용 가능.
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; // 순수가상함수 실제메모리 할당이 불가능해지는 문법.

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}

// 게임에서 사용되는 데이터들의 종류

// 이미지, 사운드, ... , 스테이지 클리어

// 저장되는 게임 플레이 데이터 -> HDD, 스팀의 경우 클라우드 저장을 한다. 이 경우도 리소스이다.
