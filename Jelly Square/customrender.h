#ifndef CUSTOMRENDER_H
#define CUSTOMRENDER_H

#include <QGraphicsView>
#include <QPen>
#include <QGraphicsScene>
#include <QRect>
#include <QMouseEvent>
#include <QTimer>
#include <simnode.h>
#include <simconnection.h>

class CustomRender : public QGraphicsView
{
	Q_OBJECT

public:
	CustomRender(QWidget *parent);
	~CustomRender();
	QPen outlinePen;
	QPen fixPen;
	QGraphicsScene * scene;
	SimNode * node;
	SimNode * fixedNode;
	SimConnection * spring;
	bool nodeDragging;
	void DrawNode(SimNode * n, QPen pen);
	void DrawConnection(SimConnection * c);
	void CUpdate();
	bool CheckCollision(QVector2D mousePos);

private:

signals :
	void sendMousePoint(QPointF point);

public slots:
	void mousePressEvent(QMouseEvent * e);
	void mouseReleaseEvent(QMouseEvent * e);
	
	//void mouseMoveEvent(QMouseEvent *move);
	
};

#endif // CUSTOMRENDER_H
