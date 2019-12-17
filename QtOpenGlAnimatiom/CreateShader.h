#pragma once
#include <QOpenGLShaderProgram>
class CreateShader
{
	QOpenGLShaderProgram m_programShader;
	
public:
	CreateShader(const QString vert, const QString frag);
	~CreateShader();

	QOpenGLShaderProgram* GetShaderProgram()
	{
		return &m_programShader;
	}
	
		
};
