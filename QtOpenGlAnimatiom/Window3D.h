#pragma once

#include <QObject>
#include <QOpenGLWindow>
#include<QOpenGLFunctions>
#include<QMatrix4x4.h>



//class Node;
//class MeshCommand;
//class Mesh;
//class MyModel3D;
class Scene;
class Window3D : public QOpenGLWindow, protected QOpenGLFunctions
{
	Q_OBJECT

		
	/*QVector< Node*> m_model;
	 MeshCommand *_commandForDraw=nullptr;
	 MeshCommand* _commandForDraw2 = nullptr;
	 Mesh* m_mesh=0;
	 Node *m = 0;*/
	 Scene* m_scene = 0;
public:
	Window3D(QOpenGLWindow::UpdateBehavior updateBehavior = NoPartialUpdate, QWindow* parent = nullptr);
	~Window3D();
	void initializeGL()override;
	void resizeGL(int w, int h)override;
	void paintGL()override;

};
