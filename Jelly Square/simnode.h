#ifndef SIMNODE_H
#define SIMNODE_H

#include <QObject>
#include <QVector2D>
#include <simconnection.h>
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
	bool fixed;
	QList<SimConnection> connects;
	void MoveNode(QVector2D newPos); 
	void UpdatePos();
	float bounceFactor;

private:
	
};

#endif // SIMNODE_H
