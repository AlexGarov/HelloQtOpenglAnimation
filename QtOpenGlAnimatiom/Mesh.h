#pragma once
class VertexBuffer;
class Mesh
{
public:
	Mesh(VertexBuffer* vertexBuffer);
	~Mesh();
	void draw();// add to Model3
protected:
	VertexBuffer* m_vertexBuffer;//in fucther Verex Data
};
