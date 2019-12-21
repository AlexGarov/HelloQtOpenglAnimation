#pragma once
#include <QOpenGLFunctions>
#include<QOpenGLTexture>
class VertexBuffer;
class Mesh;
class MeshCommand
{
public:
	MeshCommand();
	void init(VertexBuffer* vertexBuffer);
	void draw(QOpenGLFunctions* glFuncs, int vertexCount, QOpenGLTexture::PixelType type, int size, int attribSizeBytes);
protected:
	VertexBuffer* m_vertexBuffer;
};

