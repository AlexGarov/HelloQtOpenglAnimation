#pragma once
#include<QOpenGLBuffer>
#include<QOpenGLShaderProgram>
#include<QVector>
struct MyMesh
{
	//QOpenGLBuffer m_vertexBuffer;
	QOpenGLShaderProgram m_shader_program;
	QMatrix4x4 m_projectionMatrix;
	QMatrix4x4 m_viewMatrix;
}; 


