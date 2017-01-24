#ifndef SIMELEMENT_H
#define SIMELEMENT_H

#include <QObject>
#include <simnode.h>
#include <simconnection.h>
#include <qlist.h>

class SimElement : public QObject
{
	Q_OBJECT

public:
	SimElement(QObject *parent, SimNode* el1, SimNode* el2, SimNode* el3, SimNode* el4);
	~SimElement();
	//refs to connected nodes and springs
	QList<SimNode*> conNodes;
	SimConnection * conSprings[4];
	void CalcInternalForces();

	//calibrated coefficients
	float intForce = 0.02;
	float baseSize = sqrt(pow(50, 2) + pow(50, 2));

	void HandleCollision();

private:
	
};

#endif // SIMELEMENT_H
