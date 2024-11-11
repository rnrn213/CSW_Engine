#pragma once
#include "cswEntity.h"

namespace csw
{
	class Resource abstract : public Entity // �߻� Ŭ���� �޸� �Ҵ� x ��ӹ޾Ƽ��� ��� ����.
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; // ���������Լ� �����޸� �Ҵ��� �Ұ��������� ����.

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}

// ���ӿ��� ���Ǵ� �����͵��� ����

// �̹���, ����, ... , �������� Ŭ����

// ����Ǵ� ���� �÷��� ������ -> HDD, ������ ��� Ŭ���� ������ �Ѵ�. �� ��쵵 ���ҽ��̴�.
