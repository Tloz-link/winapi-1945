#pragma once

class LineMesh;
class ResourceBase;

class ResourceManager
{
	DECRATE_SINGLE(ResourceManager);

public:
	~ResourceManager();

	void Init();
	void Clear();

	const LineMesh* GetLineMesh(wstring key);

private:
	unordered_map<wstring, LineMesh*> _lineMeshes;
};

