#pragma once
#include "Node.h"
class Scene :public Node
{
public:
	virtual bool init()override;
	virtual void render(QOpenGLFunctions* glFuncs);
	
};

