#ifndef CUSTOMRENDER_H
#define CUSTOMRENDER_H
using namespace std;

#include <QGraphicsView>
#include <QPen>
#include <QGraphicsScene>
#include <QRect>
#include <QMouseEvent>
#include <QTimer>
#include <simnode.h>
#include <simconnection.h>
#include <simelement.h>
#include <QGraphicsTextItem>
#include <QList>

class CustomRender : public QGraphicsView
{
	Q_OBJECT

public:
	CustomRender(QWidget *parent);
	~CustomRender();
	//pens
	QPen mainPen;
	QPen fixPen;
	QPen forcePen2;
	QPen forcePen;

	QGraphicsScene * scene;

	//save nodes & springs
	QVector2D gridSize = { 4,4 };
	SimNode* nodes[4][4];
	SimConnection* springs[24];
	SimElement* elements[9];
	
	//variables for dragging tracking
	SimNode * draggedNode;
	bool nodeDragging;

	//FUNCTIONS
	//logic
	void CUpdate();
	bool CheckCollision(QVector2D mousePos);
	void InitSimulation();
	//drawing
	void DrawNode(SimNode * n, QPen pen);
	void DrawConnection(SimConnection * c);
	void DrawForce(QVector2D force, SimNode* node, QPen pen);

	QList<SimNode*> nodeList;
	QList<SimConnection*> springList;

private:

signals :
	void ResetMass(int value);
	void ResetSpring(int value);
	void ResetDamper(int value);
	void ResetResistance(int value);
	void ResetPressure(int value);


public slots:
	//mouse handling
	void mousePressEvent(QMouseEvent * e);
	void mouseReleaseEvent(QMouseEvent * e);
	//UI input
	void ChangeMass(int value);
	void ChangeSpring(int value);
	void ChangeDamper(int value);
	void ChangeResistance(int value);
	void ChangePressure(int value);
	void ResetSimulation();
	
};

#endif // CUSTOMRENDER_H
