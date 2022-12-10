#include "pch.h"
#include "LineMesh.h"
#include <fstream>

LineMesh::LineMesh()
{

}

LineMesh::~LineMesh()
{

}

void LineMesh::Save(wstring path)
{
	wofstream file;
	file.open(path);

	int32 minX = INT32_MAX;
	int32 minY = INT32_MAX;
	int32 maxX = INT32_MIN;
	int32 maxY = INT32_MIN;

	for (auto& line : _lines)
	{
		POINT from = line.first;
		POINT to = line.second;

		minX = min(min(minX, from.x), to.x);
		minY = min(min(minY, from.y), to.y);
		maxX = max(max(maxX, from.x), to.x);
		maxY = max(max(maxY, from.y), to.y);
	}

	int32 midX = (minX + maxX) / 2;
	int32 midY = (minY + maxY) / 2;

	file << static_cast<int32>(_lines.size()) << endl;

	for (auto& line : _lines)
	{
		POINT from = line.first;
		POINT to = line.second;

		from.x -= midX;
		from.y -= midY;
		to.x -= midX;
		to.y -= midY;

		wstring str = format(L"({0},{1})->({2},{3})", from.x, from.y, to.x, to.y);
		file << str << endl;
	}

	file.close();
}

void LineMesh::Load(wstring path)
{
	wifstream file;
	file.open(path);

	int32 size;
	file >> size;

	_lines.clear();

	for (int32 i = 0; i < size; ++i)
	{
		POINT from;
		POINT to;

		wstring str;
		file >> str;
		::swscanf_s(str.c_str(), L"(%d,%d)->(%d,%d)", &from.x, &from.y, &to.x, &to.y);
		_lines.push_back(make_pair(from, to));
	}

	file.close();
}

void LineMesh::Render(HDC hdc, Pos pos) const
{
	for (auto& line : _lines)
	{
		POINT pt1 = line.first;
		POINT pt2 = line.second;

		Pos pos1;
		pos1.x = (float)pt1.x + pos.x;
		pos1.y = (float)pt1.y + pos.y;

		Pos pos2;
		pos2.x = (float)pt2.x + pos.x;
		pos2.y = (float)pt2.y + pos.y;

		Utils::DrawLine(hdc, pos1, pos2);
	}
}
