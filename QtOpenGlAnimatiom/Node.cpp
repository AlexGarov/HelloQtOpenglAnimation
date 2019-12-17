#include "Node.h"

void Node::draw(QOpenGLFunctions* glFuncs/*Renderer* renderer, const QMatrix4x4& transform, uint32_t flags*/)
{
	//Must be empty
}

void Node::addChild(Node* child)
{
	_children.push_back(child);
	_parent = this;
}

void Node::removeChild(Node* child)
{
	auto iter = std::find(_children.begin(), _children.end(), child);
	if (iter != _children.end())
	{
		auto index=iter-_children.begin();
		auto it = std::next(_children.begin(), index);
		//(*it)->release();
		delete *it;
		_children.erase(it);
	}
	
}

void Node::setTranslate(const QVector3D& m)
{
	model.setToIdentity();
	m_model.translate(m);
}
