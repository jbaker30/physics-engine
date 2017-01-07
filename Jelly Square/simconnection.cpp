#include "simconnection.h"

//SimConnection::SimConnection(QObject *parent)
//	: QObject(parent)
//{
//
//}

SimConnection::SimConnection(QObject *parent, SimNode * start, SimNode * end)
{
	conNodes[0] = start;
	conNodes[1] = end;
	CalcForces();
}

SimConnection::~SimConnection()
{

}

void SimConnection::CalcForces()
{
	vect = conNodes[0]->pos - conNodes[1]->pos;
	extension = (vect.length() - baseLength)/vect.length();
	conNodes[0]->forces.append((vect * extension * -k) + (vect * c));
	conNodes[1]->forces.append((vect * extension * k) + (vect * -c));
}
