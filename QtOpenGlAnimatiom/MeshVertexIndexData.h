#pragma once


#include "Bundler3Ddata.h"
class MeshData;
class VertexBuffer;

class MeshVertexData
{
	
public:
	 MeshVertexData(const MeshData& meshdata);
	 ~MeshVertexData();
	 void bind();//temp
	 MeshVertexAttrib *getMeshVertexAttrib()const;
	 int getVertexSize()const;
	 VertexBuffer * getVertexBuffer()const;
protected:
	VertexBuffer* m_vertexBuffer;
	MeshVertexAttrib* m_meshVertexAttrib;
	int m_vertexSize;
};


