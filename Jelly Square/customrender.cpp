#include "customrender.h"

CustomRender::CustomRender(QWidget *parent)
	: QGraphicsView(parent)
{
	nodeDragging = false;
	scene = new QGraphicsScene;
	QSize viewSize = size();
	scene->setSceneRect(10, 10, viewSize.width(), viewSize.height());
	setScene(scene);

	outlinePen.setWidth(2);
	outlinePen.setColor(Qt::red);

	/*fixedNode = new SimNode(this);
	fixedNode->lastPos = (QVector2D(300, 250));
	fixedNode->MoveNode(QVector2D(300, 250));
	DrawNode(fixedNode);*/

	node = new SimNode(this);
	node->lastPos = (QVector2D(400, 250));
	node->MoveNode(QVector2D(400, 250));

	
	outlinePen.setColor(Qt::black);
	DrawNode(node);
}

CustomRender::~CustomRender()
{

}

void CustomRender::mousePressEvent(QMouseEvent * e)
{
	QPoint pos = e->pos();
	QVector2D posVect = (QVector2D)pos;
	if (CheckCollision(posVect))
	{
		nodeDragging = true;
		node->vel = QVector2D(0, 0);
	}
}

void CustomRender::mouseReleaseEvent(QMouseEvent * e)
{
	nodeDragging = false;
}


void CustomRender::CUpdate()
{
	scene->clear();
	if (nodeDragging)
	{
		QVector2D mousePos = (QVector2D)mapFromGlobal(QCursor::pos());
		node->MoveNode(mousePos);
	}
	else
	{
		node->UpdatePos();
	}
	DrawNode(node);
	//DrawNode(fixedNode);
}

void CustomRender::DrawNode(SimNode * n)
{
	scene->addEllipse(n->pos.x(), n->pos.y(), 20, 20, outlinePen);
}

bool CustomRender::CheckCollision(QVector2D mousePos)
{
	//for each node
	int diff = mousePos.distanceToPoint(node->pos);
	if (diff < 10)
		return true;
	else
		return false;
}
