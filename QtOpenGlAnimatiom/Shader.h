#pragma once
#include <QOpenGLShader>
#include<QOpenGLTexture>
namespace Shader
{
	 
	void initShader();
	void shaderMeshBind1(const QMatrix4x4& model);
	void shaderMeshBind2(QOpenGLTexture::PixelType type, int size, int attribSizeBytes);
}

