#include "Bundler3D.h"
#include "ObjLoader.h"


bool Bundler3D::loadObj(MeshDatas& meshdatas, const QString& s, const float p[],int size)
{
	meshdatas.resetData();


	QVector<tinyobj::shape_t> shapes;
	tinyobj::LoadObj(shapes,s,p, size);

	//convert mesh
	for (auto& shape : shapes)
	{
		auto mesh = shape.mesh;
		MeshData* meshdata = new (std::nothrow) MeshData;
		MeshVertexAttrib attrib;
		attrib.size = 3;
		attrib.type = QOpenGLTexture::Float32; //GL_FLOAT

		if (mesh.positions.size())
		{
			attrib.vertexAttrib = "a_VERTEX_ATTRIB_POSITION";
			attrib.attribSizeBytes = attrib.size * sizeof(float);
			meshdata->attribs.push_back(attrib);

		}

		//if (mesh.texcoords.size())
		//{
		//	//hastex = true;
		//	attrib.size = 2;
		//	attrib.vertexAttrib = "a_VERTEX_ATTRIB_TEX_COORD";
		//	attrib.attribSizeBytes = attrib.size * sizeof(float);
		//	meshdata->attribs.push_back(attrib);
		//}
		auto vertexNum = mesh.positions.size() / 3;
		for (unsigned int k = 0; k < vertexNum; ++k)
		{
			meshdata->vertex.push_back(mesh.positions[k * 3]);
			meshdata->vertex.push_back(mesh.positions[k * 3 + 1]);
			meshdata->vertex.push_back(mesh.positions[k * 3 + 2]);

			

			
				/*meshdata->vertex.push_back(mesh.texcoords[k * 2]);
				meshdata->vertex.push_back(mesh.texcoords[k * 2 + 1]);*/
			
		}
		meshdatas.meshDatas.push_back(meshdata);
		return true;
	}

	return false;
}
