#pragma once
#include "Node.h"
#include <QString>
#include <QOpenGLFunctions>
//class VertexBuffer;
class MeshVertexData;
class Mesh;
class MyModel3D: public Node
{
	
public:
	MyModel3D(const QString& s,const float p[],int size);
	virtual void draw(QOpenGLFunctions* glFuncs/*Renderer* renderer, const QMatrix4x4& transform, uint32_t flags*/)/*override*/;
private:
	void init(const QString& s,const float p[], int size);
	void meshCreate();
protected:
	QVector<MeshVertexData*> m_meshVertexData;

	QVector<Mesh*> m_mesh;
};

