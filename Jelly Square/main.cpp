#include "jellysquare.h"
#include <QtWidgets/QApplication>

//global variables
float grav = 5;


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	JellySquare w;
	w.show();
	return a.exec();
}
