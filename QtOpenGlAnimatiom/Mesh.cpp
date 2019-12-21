#include "Mesh.h"
#include"MeshVertexIndexData.h"


Mesh::Mesh(MeshVertexData* meshVertexData):m_meshVertexData(meshVertexData)
{
	m_meshCommand.init(getVertexBuffer());
}

Mesh::~Mesh()
{
	delete m_meshVertexData;
}

VertexBuffer* Mesh::getVertexBuffer()
{
	return m_meshVertexData->getVertexBuffer();
}

void Mesh::draw(QOpenGLFunctions* glFuncs)
{
	m_meshCommand.draw(glFuncs,
		m_meshVertexData->getVertexSize() / m_meshVertexData->getMeshVertexAttrib()->size,
		m_meshVertexData->getMeshVertexAttrib()->type,
		m_meshVertexData->getMeshVertexAttrib()->size,
		m_meshVertexData->getMeshVertexAttrib()->attribSizeBytes);
}
