#pragma once
#include<qmatrix4x4.h>
class Renderer;
class QOpenGLFunctions;
class Node
{
	
public:
	virtual void draw(QOpenGLFunctions* glFuncs/*Renderer* renderer, const QMatrix4x4& transform, uint32_t flags*/);
	virtual void addChild(Node* child);
	virtual void removeChild(Node* child/*, bool cleanup = true*/);
	virtual void setTranslate(const QVector3D& m);
protected:
	QVector<Node*> _children;        ///< array of children nodes
	Node* _parent;
	QMatrix4x4 _model;
};

