
#include<assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "ModelWareHouse.h"
#include "Window3D.h"
ModelWareHouse::ModelWareHouse()	
{
   
}

ModelWareHouse::~ModelWareHouse()
{
}

void ModelWareHouse::InitAndLoadFromAssimp()
{
    // read file via ASSIMP
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile("C:\\Users\\korch\\Documents\\untitled2.dae",  aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
    // check for errors
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
    {
       qDebug() << "ERROR::ASSIMP:: " << importer.GetErrorString();
        return;
    }
   
    ProcessNode(scene->mRootNode, scene);
}
void ModelWareHouse::ProcessNode(aiNode* node, const aiScene* scene)
{
    qDebug() << node->mName.C_Str();
    // process each mesh located at the current node
    for (unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        // the node object only contains indices to index the actual objects in the scene. 
        // the scene contains all the data, node is just to keep stuff organized (like relations between nodes).
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        //meshes.push_back(processMesh(mesh, scene));
        for (unsigned int j = 0; j < mesh->mNumVertices; j++)
        qDebug() << mesh->mVertices[j].x << " " << mesh->mVertices[j].y << " " << mesh->mVertices[j].z;
    }
    // after we've processed all of the meshes (if any) we then recursively process each of the children nodes
    if (node->mNumChildren)
    {
        qDebug()<<"Children" << node->mNumChildren;
        for (unsigned int i = 0; i < node->mNumChildren; i++)
        {
            ProcessNode(node->mChildren[i], scene);
        }
    }
    


}
