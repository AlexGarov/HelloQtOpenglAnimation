#include "MyModel3D.h"
#include "Bundler3Ddata.h"
#include"Bundler3D.h"
#include"Global.h"
#include"VertexIndexBuffer.h"
#include<qdebug.h>

extern struct MyMesh g_mesh_t;
MyModel3D::MyModel3D(const QString& s,const float p[], int size)
{
	init(s, p,size);
}

void MyModel3D::draw(QOpenGLFunctions* glFuncs/*Renderer* renderer, const QMatrix4x4& transform, uint32_t flags*/)
{
	
	g_mesh_t.m_shader_program.bind();
	g_mesh_t.m_shader_program.setUniformValue("u_mvp", g_mesh_t.m_projectionMatrix * g_mesh_t.m_viewMatrix* m_model);
	vertexBuffer->bind();
	int offset = 0;
	int vertLoc = g_mesh_t.m_shader_program.attributeLocation("a_position");
	g_mesh_t.m_shader_program.enableAttributeArray(vertLoc);
	g_mesh_t.m_shader_program.setAttributeBuffer(vertLoc, GL_FLOAT, offset, 3, 3 * sizeof(float));
	glFuncs->glDrawArrays(GL_TRIANGLES, 0, 36);
	
}

void MyModel3D::init(const QString& s,const float p[],int size)
{
	MeshDatas* meshdatas = new (std::nothrow) MeshDatas;
	Bundler3D::loadObj(*meshdatas, s, p, size);
	for (auto& meshdata : meshdatas->meshDatas)
	{
		vertexBuffer = new VertexBuffer(meshdata->vertex.constData(), meshdata->vertex.size() * sizeof(float));
		
	}
	
}
