#pragma once
#include <QVector>
#include<QOpenGLTexture>
struct MeshVertexAttrib
{
    //attribute size
    int size;
    //GL_FLOAT
    QOpenGLTexture::PixelType type;
    //VERTEX_ATTRIB_POSITION,VERTEX_ATTRIB_COLOR,VERTEX_ATTRIB_TEX_COORD,VERTEX_ATTRIB_NORMAL, VERTEX_ATTRIB_BLEND_WEIGHT, VERTEX_ATTRIB_BLEND_INDEX, GLProgram for detail
    //int  vertexAttrib;
    QString vertexAttrib;
    //size in bytes
    int attribSizeBytes;
};
struct MeshData
{
   // typedef std::vector<unsigned short> IndexArray;
     QVector<float> vertex;
    int vertexSizeInFloat;
    //std::vector<IndexArray> subMeshIndices;
    //std::vector<std::string> subMeshIds; //subMesh Names (since 3.3)
    //std::vector<AABB> subMeshAABB;
    //int numIndex;
    QVector<MeshVertexAttrib> attribs;
    int attribCount;

public:
    /**
     * Get per vertex size
     * @return return the sum of each vertex's all attribute size.
     */
    int getPerVertexSize() const
    {
        int vertexsize = 0;
        for (const auto& attrib : attribs)
        {
            vertexsize += attrib.attribSizeBytes;
        }
        return vertexsize;
    }

    /**
     * Reset the data
     */
    void resetData()
    {
        vertex.clear();
        //subMeshIndices.clear();
       // subMeshAABB.clear();
        attribs.clear();
        vertexSizeInFloat = 0;
        //numIndex = 0;
        attribCount = 0;
    }
    MeshData()
        : vertexSizeInFloat(0)
        //, numIndex(0)
        , attribCount(0)
    {
    }
    ~MeshData()
    {
        resetData();
    }
};

struct MeshDatas
{
    std::vector<MeshData*> meshDatas;

    void resetData()
    {
        for (auto& it : meshDatas)
        {
            delete it;
        }
        meshDatas.clear();
    }
    ~MeshDatas()
    {
        resetData();
    }
};

