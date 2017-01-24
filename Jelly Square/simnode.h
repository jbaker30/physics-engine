#ifndef SIMNODE_H
#define SIMNODE_H

#include <QObject>
#include <QVector2D>
//#include <simconnection.h>
#include <QList>

class SimNode : public QObject
{
	Q_OBJECT

public:
	SimNode(QObject *parent, QVector2D startPos);
	~SimNode();
	//current state variables
	QVector2D pos;
	QVector2D lastPos; 
	QVector2D vel;
	QVector2D acc;
	QList<QVector2D> forces;
	bool fixed = false;
	bool dragging = false;
	
	//refs for springs connected
	QList<int> connectIDs;
	
	//functions
	void MoveNode(QVector2D newPos);
	void Collide(QVector2D planeVect);
	void CalcForces();
	void UpdatePos();

	//coefficients to be calibrated
	float bounceFactor;
	float resistance;
	float mass;

private:
	
};

#endif // SIMNODE_H
