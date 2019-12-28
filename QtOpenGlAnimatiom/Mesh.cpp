#include "Mesh.h"
#include"MeshVertexIndexData.h"


Mesh::Mesh(MeshVertexData* meshVertexData):m_meshVertexData(meshVertexData)
{
	m_meshCommand.init(getVertexBuffer(),
		m_meshVertexData->getVertexSize() / m_meshVertexData->getMeshVertexAttrib()->size,
		m_meshVertexData->getMeshVertexAttrib()->type,
		m_meshVertexData->getMeshVertexAttrib()->size,
		m_meshVertexData->getMeshVertexAttrib()->attribSizeBytes);
}

Mesh::~Mesh()
{
	delete m_meshVertexData;
}

VertexBuffer* Mesh::getVertexBuffer()
{
	return m_meshVertexData->getVertexBuffer();
}

void Mesh::draw(QOpenGLFunctions* glFuncs, QMatrix4x4 &model)
{
	m_meshCommand.draw(glFuncs, model);
}
