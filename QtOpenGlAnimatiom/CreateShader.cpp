#include "CreateShader.h"


CreateShader::CreateShader(const QString vert, const QString frag)
{
    if (!m_programShader.addShaderFromSourceFile(QOpenGLShader::Vertex, vert))
        m_programShader.log();

    if (!m_programShader.addShaderFromSourceFile(QOpenGLShader::Fragment, frag))
        m_programShader.log();
    
    if (!m_programShader.link())
        m_programShader.log();

    m_programShader.bind();


}

CreateShader::~CreateShader()
{
    m_programShader.deleteLater();
    
}
