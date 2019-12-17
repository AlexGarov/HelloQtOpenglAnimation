#include "MeshVertexIndexData.h"
#include"VertexIndexBuffer.h"
//#include"Bundler3Ddata.h"


MeshVertexData::MeshVertexData(const MeshData& meshdata)
{
	m_vertexSize = meshdata.vertex.size();
	m_vertexBuffer = new VertexBuffer(meshdata.vertex.constData(), m_vertexSize * sizeof(float));
	m_meshVertexAttrib = new MeshVertexAttrib;
	m_meshVertexAttrib->attribSizeBytes= meshdata.attribs[0].attribSizeBytes;
	m_meshVertexAttrib->size = meshdata.attribs[0].size;
	m_meshVertexAttrib->type = meshdata.attribs[0].type;
	m_meshVertexAttrib->vertexAttrib = meshdata.attribs[0].vertexAttrib;
}

MeshVertexData::~MeshVertexData()
{
	m_vertexBuffer->~VertexBuffer();
	delete m_vertexBuffer;
	delete m_meshVertexAttrib;
}

void MeshVertexData::bind()
{
	m_vertexBuffer->bind();
}

MeshVertexAttrib* MeshVertexData::getMeshVertexAttrib()const
{
	return m_meshVertexAttrib;
}

int MeshVertexData::getVertexSize() const
{
	return m_vertexSize;
}

VertexBuffer* MeshVertexData::getVertexBuffer() const
{
	return m_vertexBuffer;
}

