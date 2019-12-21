#pragma once
//#include <QOpenGLFunctions>
#include"MeshCommand.h"
class MeshVertexData;
class VertexBuffer;
class Mesh
{
public:
	Mesh(MeshVertexData* meshVertexData);
	
	~Mesh();
	VertexBuffer* getVertexBuffer();

	void draw(QOpenGLFunctions* glFuncs);// add to Model3
protected:
	MeshVertexData* m_meshVertexData;//in fucther Verex Data
	MeshCommand         m_meshCommand;
};
