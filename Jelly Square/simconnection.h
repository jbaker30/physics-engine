#ifndef SIMCONNECTION_H
#define SIMCONNECTION_H

#include <array>
#include <QObject>
#include <QVector2D>
#include <QList>
#include <simnode.h>

class SimConnection : public QObject
{
	Q_OBJECT

public:
	//SimConnection(QObject *parent);
	SimConnection(QObject *parent, SimNode * start, SimNode * end, int ID);
	~SimConnection();
	QVector2D vect;
	QVector2D springForce;
	QVector2D dampingForce;
	float extension;
	float lastExtension;
	float vel;
	float minLength = 50;
	float maxLength = 0;
	const float baseLength = 100;
	const float intPressure = 0.2;
	float angleExtension;
	std::array<SimNode*, 2> conNodes;
	float tension;
	float k = 0.2;
	float scaledK = 0.2;
	float c = 0.05;
	void CalcSpringForces();
	void HandleCollision(QList<SimNode*> possNodes, QList<SimConnection*> springs);
	void HandleMinLength();

private:
	
};

#endif // SIMCONNECTION_H
