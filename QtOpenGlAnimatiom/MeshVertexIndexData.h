#pragma once
#include<QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

#include "Bundler3Ddata.h"
class MeshVertexData
{
	//QOpenGLVertexArrayObject m_VAO;
	QOpenGLBuffer m_vertexBuffer;//position,texture, normal 
	//QOpenGLBuffer m_indexBuffer;
public:
	 MeshVertexData* Create(const MeshData& meshdata);
};


