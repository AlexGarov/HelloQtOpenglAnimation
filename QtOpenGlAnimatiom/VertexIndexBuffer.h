#pragma once
#include<QOpenGLBuffer>
class VertexBuffer
{
	QOpenGLBuffer m_vertexBuffer;
public:
	VertexBuffer(const void* data, int count);
	~VertexBuffer();
	void bind();


};

class IndexBuffer
{
	QOpenGLBuffer m_indexBuffer;
public:
	IndexBuffer(const void* data, int count);
	~IndexBuffer();
	void bind();


};