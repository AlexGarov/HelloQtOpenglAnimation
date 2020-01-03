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
	_model.setToIdentity();
	_model.translate(m);
}

bool Node::init()
{
	return true;
}

void Node::visit(QOpenGLFunctions* glFuncs)
{
	if (!_children.empty())
	{
		this->draw(glFuncs);
		for (auto it = _children.cbegin(), itCend = _children.cend(); it != itCend; ++it)
			(*it)->visit(glFuncs);
	}
	else
	{
		this->draw(glFuncs);
	}
	
}
