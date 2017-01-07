#include "jellysquare.h"

JellySquare::JellySquare(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QTimer * timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(Update()));
	timer->start(20);
	draggedNode = NULL;
	
}

JellySquare::~JellySquare()
{

}

void JellySquare::Update()
{
	ui.graphicsView->CUpdate();
}


//void JellySquare::MoveNode(QVector2D newPos)
//{
//
//}

