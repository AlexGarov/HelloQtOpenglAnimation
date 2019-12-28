#include "MyModel3D.h"
#include "Bundler3Ddata.h"
#include"Bundler3D.h"
#include"Global.h"
#include"VertexIndexBuffer.h"
#include"MeshVertexIndexData.h"
#include"Mesh.h"
#include<qdebug.h>

extern struct MyMesh g_mesh_t;
MyModel3D::MyModel3D(const QString& s,const float p[], int size)
{
	init(s, p,size);
}

void MyModel3D::draw(QOpenGLFunctions* glFuncs/*Renderer* renderer, const QMatrix4x4& transform, uint32_t flags*/)
{
	
	
	
	m_mesh[0]->draw(glFuncs,_model);
}

void MyModel3D::init(const QString& s,const float p[],int size)
{
	MeshDatas* meshdatas = new (std::nothrow) MeshDatas;
	Bundler3D::loadObj(*meshdatas, s, p, size);
	for (auto& meshdata : meshdatas->meshDatas)
	{
		//vertexBuffer = new VertexBuffer(meshdata->vertex.constData(), meshdata->vertex.size() * sizeof(float));
		MeshVertexData* meshVertexData = new MeshVertexData(*meshdata);
		m_meshVertexData.push_back(meshVertexData);
	}
	meshCreate();
}

void MyModel3D::meshCreate()
{
	auto mesh = new Mesh(m_meshVertexData[0]);
	m_mesh.push_back(mesh);
}
