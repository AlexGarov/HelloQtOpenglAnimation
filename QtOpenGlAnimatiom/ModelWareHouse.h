#pragma once
#include"CreateShader.h"
#include<assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
class Window3D;
class ModelWareHouse
{
	
	//CreateShader m_shader;
public:
	ModelWareHouse();
	~ModelWareHouse();
	void InitAndLoadFromAssimp();
	void ProcessNode(aiNode* node, const aiScene* scene);

};
