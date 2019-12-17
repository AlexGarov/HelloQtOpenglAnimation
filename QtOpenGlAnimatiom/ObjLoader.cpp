#include "ObjLoader.h"
//#include"ModelShapStorage.h"

void tinyobj::LoadObj(QVector<shape_t>& shapes, const QString &s, const float p[],int size)
{
	
	
	shape_t shape;
	// name shape
	shape.name = s;
	// position coord
	//unsigned dataArraySize = sizeof(p) / sizeof(float);
	unsigned dataArraySize = size;
	//int size = *(&p + 1) - p;
	std::copy(&p[0], &p[dataArraySize], std::back_inserter(shape.mesh.positions));
	//texture coordinat
	/*dataArraySize = sizeof(p) / sizeof(float);
	std::copy(&p[0], &Cube_Texture::texture[dataArraySize], std::back_inserter(shape.mesh.texcoords));*/
	shapes.append(shape);
}
