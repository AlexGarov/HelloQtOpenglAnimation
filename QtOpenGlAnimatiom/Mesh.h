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

	void draw(QOpenGLFunctions* glFuncs, QMatrix4x4& model);// add to Model3
protected:
	MeshVertexData* m_meshVertexData;//in fucther Verex Data
	MeshCommand         m_meshCommand;
};
