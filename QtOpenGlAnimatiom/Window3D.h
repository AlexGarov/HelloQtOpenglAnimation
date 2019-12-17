#pragma once

#include <QObject>
#include <QOpenGLWindow>
#include<QOpenGLFunctions>
#include<QMatrix4x4.h>



class Node;
class Window3D : public QOpenGLWindow, protected QOpenGLFunctions
{
	Q_OBJECT

		
	QVector< Node*> m_model;
public:
	Window3D(QOpenGLWindow::UpdateBehavior updateBehavior = NoPartialUpdate, QWindow* parent = nullptr);
	~Window3D();
	void initializeGL()override;
	void resizeGL(int w, int h)override;
	void paintGL()override;

};
