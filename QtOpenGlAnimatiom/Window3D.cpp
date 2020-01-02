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
	/*_commandForDraw = new MeshCommand;
	m_mesh = new Mesh;*/
	
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
	//m=new MyModel3D(Cube_Texture::name, Cube_Texture::position_points, Cube_Texture::position_size);
	//m->setTranslate(QVector3D(-2, 0, 0));
	//m_model.append(m);
	//m_commandForDraw.append(m->draw(QOpenGLContext::currentContext()->functions(),m->_model));
	//_commandForDraw=m->m_mesh[0]->m_meshCommand;
	
	//m_mesh->m_meshCommand = m->_mesh->m_meshCommand;
	//MyModel3D* mm = dynamic_cast<MyModel3D*>(m);
	//_commandForDraw = mm->_mesh->m_meshCommand.getMeshCommand();
	
	//MyModel3D *m2= new MyModel3D(Triangle::name, Triangle::position_points, Triangle::position_size);
	//m2->setTranslate(QVector3D(2, 0, 0));
	////m_model.append(m2);
	////_commandForDraw = m2->m_mesh[0]->m_meshCommand;
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
	//_commandForDraw->draw(QOpenGLContext::currentContext()->functions(), m->_model);
	/*for (auto& ref : m_model)
	{
		ref->draw(QOpenGLContext::currentContext()->functions());
	}*/
	
	m_scene->render(QOpenGLContext::currentContext()->functions());
	

}





