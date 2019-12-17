#include "VertexIndexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, int count)
{
	m_vertexBuffer.create();
	m_vertexBuffer.bind();
	m_vertexBuffer.allocate(data, count);
	m_vertexBuffer.release();
}

VertexBuffer::~VertexBuffer()
{
	m_vertexBuffer.destroy();
}

void VertexBuffer::bind()
{
	m_vertexBuffer.bind();
}

IndexBuffer::IndexBuffer(const void* data, int count):m_indexBuffer(QOpenGLBuffer::IndexBuffer)
{
	m_indexBuffer.create();
	m_indexBuffer.bind();
	m_indexBuffer.allocate(data, count);
	m_indexBuffer.release();
}

IndexBuffer::~IndexBuffer()
{
	m_indexBuffer.destroy();
}

void IndexBuffer::bind()
{
	m_indexBuffer.bind();
}
