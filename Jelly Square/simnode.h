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
	SimNode(QObject *parent);
	~SimNode();
	QVector2D pos;
	QVector2D lastPos;
	QVector2D vel;
	QVector2D acc;
	bool fixed;
	//QList<SimConnection*> connects;
	QList<QVector2D> forces;
	void MoveNode(QVector2D newPos); 
	void UpdatePos();
	float bounceFactor;
	float resistance;

private:
	
};

#endif // SIMNODE_H
