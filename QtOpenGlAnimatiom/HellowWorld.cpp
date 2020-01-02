#include "HellowWorld.h"
#include"ModelShapStorage.h"
HellowWorld::HellowWorld()
{
	init();
}

bool HellowWorld::init()
{
	if (!Scene::init())
	{
		return false;
	}

	MyModel3D *modelCube= new MyModel3D(Cube_Texture::name, Cube_Texture::position_points, Cube_Texture::position_size);
	modelCube->setTranslate(QVector3D(-2, 0, 0));
	this->addChild(modelCube);

	MyModel3D *triangle= new MyModel3D(Triangle::name, Triangle::position_points, Triangle::position_size);
	triangle->setTranslate(QVector3D(2, 0, 0));
	this->addChild(triangle);
}
