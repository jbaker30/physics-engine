#include "customrender.h"

CustomRender::CustomRender(QWidget *parent)
	: QGraphicsView(parent)
{
	nodeDragging = false;
	scene = new QGraphicsScene;
	QSize viewSize = size();
	scene->setSceneRect(10, 10, viewSize.width(), viewSize.height());
	setScene(scene);

	fixPen.setWidth(2);
	fixPen.setColor(Qt::red);
	outlinePen.setWidth(2);
	outlinePen.setColor(Qt::black);

	fixedNode = new SimNode(this);
	fixedNode->lastPos = (QVector2D(400, 150));
	fixedNode->MoveNode(QVector2D(400, 150));
	DrawNode(fixedNode, fixPen);

	node = new SimNode(this);
	node->lastPos = (QVector2D(400, 250));
	node->MoveNode(QVector2D(400, 250));

	spring = new SimConnection(this, fixedNode, node);
	DrawNode(node, outlinePen);
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
		node->forces.clear();
		fixedNode->forces.clear();
		spring->CalcForces();
		node->UpdatePos();
	}
	DrawNode(node, outlinePen);
	DrawNode(fixedNode, fixPen);
	DrawConnection(spring);
}

void CustomRender::DrawNode(SimNode * n, QPen pen)
{
	scene->addEllipse(n->pos.x(), n->pos.y(), 20, 20, pen);
}

void CustomRender::DrawConnection(SimConnection * c)
{
	scene->addLine(c->conNodes[0]->pos.x() + 10, c->conNodes[0]->pos.y() + 10,
		c->conNodes[1]->pos.x() + 10, c->conNodes[1]->pos.y() + 10, outlinePen);
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
