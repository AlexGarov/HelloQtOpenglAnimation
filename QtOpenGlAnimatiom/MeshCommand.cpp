#include "MeshCommand.h"
#include"VertexIndexBuffer.h"
#include "Global.h"
extern struct MyMesh g_mesh_t;
MeshCommand::MeshCommand()
{
}

void MeshCommand::init(VertexBuffer* vertexBuffer)
{
	m_vertexBuffer=vertexBuffer;
}

void MeshCommand::draw(QOpenGLFunctions* glFuncs, int vertexCount, QOpenGLTexture::PixelType type, int size, int attribSizeBytes)
{
	m_vertexBuffer->bind();
	int offset = 0;
	int vertLoc = g_mesh_t.m_shader_program.attributeLocation("a_position");
	g_mesh_t.m_shader_program.enableAttributeArray(vertLoc);
	g_mesh_t.m_shader_program.setAttributeBuffer(vertLoc, type, offset,	size, attribSizeBytes);
	glFuncs->glDrawArrays(GL_TRIANGLES, 0, vertexCount);

}
