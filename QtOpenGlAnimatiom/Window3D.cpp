#include "Window3D.h"
//#include "Bundler3Ddata.h"
//#include"Bundler3D.h"
#include"ModelShapStorage.h"
#include"MyModel3D.h"
#include"Global.h"
#include"Shader.h"
#include<QOpenGLBuffer>
//#include<QOpenGLShaderProgram>
#include<QVector>
//void initCube();
//void initShader();
//void paintCube();
extern struct MyMesh g_mesh_t;
/* struct Mymesh
{
	QOpenGLBuffer m_vertexBuffer;
	QOpenGLShaderProgram m_shader_program;
	QMatrix4x4 m_projectionMatrix;
	QMatrix4x4 m_viewMatrix;
} my_mesh_t;*/

Window3D::Window3D(QOpenGLWindow::UpdateBehavior updateBehavior , QWindow* parent )
	: QOpenGLWindow(updateBehavior, parent)
{
	
}

Window3D::~Window3D()
{
}

void Window3D::initializeGL()
{
	initializeOpenGLFunctions();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	Shader::initShader();
	
	Node *m=new MyModel3D(Cube_Texture::name, Cube_Texture::position_points, Cube_Texture::position_size);
	m->setTranslate(QVector3D(-2, 0, 0));
	m_model.append(m);
	Node *m2= new MyModel3D(Triangle::name, Triangle::position_points, Triangle::position_size);
	m2->setTranslate(QVector3D(2, 0, 0));
	m_model.append(m2);
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
	for (auto& ref : m_model)
	{
		ref->draw(QOpenGLContext::currentContext()->functions());
	}
	
	
	

}





