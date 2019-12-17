#include"Window3D.h"
#include"ModelWareHouse.h"
#include"ObjLoader.h"
#include"Bundler3Ddata.h"
#include"Bundler3D.h"
#include"HelloCube.h"
#include <QtCore/QCoreApplication>
#include <QtGui/QGuiApplication>

int main(int argc, char *argv[])
{
	QGuiApplication a(argc, argv);	
    Window3D window;
	window.show();
	return a.exec();
}
