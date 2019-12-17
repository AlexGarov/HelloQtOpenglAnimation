#include "MeshVertexIndexData.h"

MeshVertexData* MeshVertexData::Create(const MeshData& meshdata)
{
    m_vertexBuffer.create();
    m_vertexBuffer.bind();
    int size_m = meshdata.vertex.size() * sizeof(float);
    m_vertexBuffer.allocate(meshdata.vertex.constData(), size_m);
    auto t = m_vertexBuffer.bufferId();
    m_vertexBuffer.release();
   
   /* m_indexBuffer.create();
    m_indexBuffer.bind();
    m_indexBuffer.allocate(indexes.constData(), indexes.size() * sizeof(GLuint));
    m_indexBuffer.release();*/
    return nullptr;
}
