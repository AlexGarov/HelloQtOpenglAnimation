#pragma once
#include <QVector>
#include<QString>
namespace tinyobj {
    typedef struct mesh {
        QVector<float> positions;

       // QVector<float> texcoords;

    } mesh_t;
  
    typedef struct shape {
        QString name;
        mesh_t mesh;
    } shape_t;

    void LoadObj(QVector<shape_t>& shapes ,      // [output]
        const QString &s,const float p[], int size        //input
     // const char* filename, const char* mtl_basepath = NULL
    );
}
