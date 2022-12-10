#pragma once
#include "ResourceBase.h"

class LineMesh : public ResourceBase
{
public:
	LineMesh();
	virtual ~LineMesh();

	void Save(wstring path);
	void Load(wstring path);

	void Render(HDC hdc, Pos pos) const;

private:
	vector<pair<POINT, POINT>> _lines;
};

