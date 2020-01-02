#include "MeshCommand.h"
#include"VertexIndexBuffer.h"
#include "Shader.h"

//extern  QOpenGLShaderProgram g_shader_program;
MeshCommand::MeshCommand()
{
}

void MeshCommand::init(VertexBuffer* vertexBuffer,
						int vertexCount, QOpenGLTexture::PixelType type,
						int size, int attribSizeBytes
						/*, QMatrix4x4& model*/)
{
	m_vertexBuffer=vertexBuffer;
	m_vertexCount= vertexCount ;
	m_type= type ;
	m_size= size ;
	m_attribSizeBytes= attribSizeBytes ;
	
}

void MeshCommand::draw(QOpenGLFunctions* glFuncs,QMatrix4x4& model)
{
	Shader::shaderMeshBind1(model);
	m_vertexBuffer->bind();
	Shader::shaderMeshBind2(m_type, m_size, m_attribSizeBytes);
	glFuncs->glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);

}

MeshCommand* MeshCommand::getMeshCommand() 
{
	return this;
}
