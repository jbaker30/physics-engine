#ifndef CUSTOMRENDER_H
#define CUSTOMRENDER_H

#include <QGraphicsView>
#include <QPen>
#include <QGraphicsScene>
#include <QRect>
#include <QMouseEvent>
#include <QTimer>
#include <simnode.h>

class CustomRender : public QGraphicsView
{
	Q_OBJECT

public:
	CustomRender(QWidget *parent);
	~CustomRender();
	QPen outlinePen;
	QGraphicsScene * scene;
	SimNode * node;
	//SimNode * fixedNode;
	bool nodeDragging;
	void DrawNode(SimNode * n);
	void DrawConnection(QVector2D pos1, QVector2D pos2);
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
