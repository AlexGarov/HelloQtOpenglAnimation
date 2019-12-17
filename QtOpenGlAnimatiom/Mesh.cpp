#include "Mesh.h"

Mesh::Mesh(VertexBuffer* vertexBuffer):m_vertexBuffer(vertexBuffer)
{

}

Mesh::~Mesh()
{
	delete m_vertexBuffer;
}

void Mesh::draw()
{
}
