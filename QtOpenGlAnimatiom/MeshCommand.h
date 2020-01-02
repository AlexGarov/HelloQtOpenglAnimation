#pragma once
#include <QOpenGLFunctions>
#include<QOpenGLTexture>
class VertexBuffer;
class Mesh;
class MeshCommand
{
public:
	MeshCommand();
	void init(VertexBuffer* vertexBuffer, int vertexCount, QOpenGLTexture::PixelType type, int size, int attribSizeBytes /*QMatrix4x4 &model*/);
	void draw(QOpenGLFunctions* glFuncs, QMatrix4x4& model);
	MeshCommand* getMeshCommand() ;
protected:
	VertexBuffer* m_vertexBuffer;
	int m_vertexCount;
	QOpenGLTexture::PixelType m_type;
	int m_size;
	int m_attribSizeBytes;
	//QMatrix4x4 m_model;
};

