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
	SimConnection(QObject *parent, SimNode * start, SimNode * end);
	~SimConnection();
	QVector2D vect;
	float extension;
	const float baseLength = 100;
	std::array<SimNode*, 2> conNodes;
	float tension;
	const float k = 0.2;
	const float c = 0.05;
	void CalcForces();

private:
	
};

#endif // SIMCONNECTION_H
