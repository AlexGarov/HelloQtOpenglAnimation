#include "Scene.h"



bool Scene::init()
{
	return true;
}

void Scene::render(QOpenGLFunctions* glFuncs)
{
	this->visit(glFuncs);
}
