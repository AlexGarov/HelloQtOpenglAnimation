#include "Window3D.h"
//#include"MeshCommand.h"
//#include"ModelShapStorage.h"
//#include"MyModel3D.h"
#include"Global.h"
#include"Shader.h"
//#include "Node.h"
//#include"Mesh.h"
//#include "Scene.h"
#include "HellowWorld.h"
#include<QOpenGLBuffer>

#include<QVector>

extern struct MyMesh g_mesh_t;


Window3D::Window3D(QOpenGLWindow::UpdateBehavior updateBehavior , QWindow* parent )
	: QOpenGLWindow(updateBehavior, parent)
{
	
}

Window3D::~Window3D()
{
	delete m_scene;
}

void Window3D::initializeGL()
{
	initializeOpenGLFunctions();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	Shader::initShader();
	m_scene = new HellowWorld;
	
	g_mesh_t.m_viewMatrix.setToIdentity();
	g_mesh_t.m_viewMatrix.translate(QVector3D(0, 0, -5));
	
	
	
}

void Window3D::resizeGL(int w, int h)
{
	GLfloat aspect = w / (GLfloat)h;
	g_mesh_t.m_projectionMatrix.setToIdentity();
	g_mesh_t.m_projectionMatrix.perspective(45, aspect, 0.01, 100);
	update();
}

void Window3D::paintGL()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	
	m_scene->render(QOpenGLContext::currentContext()->functions());
	

}





