#include "Shader.h"
#include "Global.h"
extern struct MyMesh g_mesh_t;
QOpenGLShaderProgram g_shader_program;
void Shader::initShader()
{
	if (!g_shader_program.addShaderFromSourceCode(QOpenGLShader::Vertex,
		"attribute highp vec3 a_position;\n"
		"uniform highp mat4 u_mvp;\n"
		"void main(void)\n"
		"{\n"
		"   gl_Position = u_mvp * vec4(a_position,1);\n"
		"}"))
	{

		qDebug() << "QOpenGLShader::Vertex";
	}
	if (!g_shader_program.addShaderFromSourceCode(QOpenGLShader::Fragment,
		"void main(void)\n"
		"{\n"
		"   gl_FragColor = vec4(1,0,0,1);\n"
		"}"))
		qDebug() << "QOpenGLShader::Fragment";

	if (!g_shader_program.link())
	{
		qDebug() << "link";

	}
}

void Shader::shaderMeshBind1(const QMatrix4x4& model)
{
	g_shader_program.bind();
	g_shader_program.setUniformValue("u_mvp", g_mesh_t.m_projectionMatrix * g_mesh_t.m_viewMatrix * model);
}

void Shader::shaderMeshBind2(QOpenGLTexture::PixelType type, int size, int attribSizeBytes)
{
	int offset = 0;
	int vertLoc = g_shader_program.attributeLocation("a_position");
	g_shader_program.enableAttributeArray(vertLoc);
	g_shader_program.setAttributeBuffer(vertLoc, type, offset, size, attribSizeBytes);
}
