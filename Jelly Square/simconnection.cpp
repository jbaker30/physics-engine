#include "simconnection.h"
#define PI 3.14159265359

//SimConnection::SimConnection(QObject *parent)
//	: QObject(parent)
//{
//
//}


//overloaded constructor to create connection between specified nodes
SimConnection::SimConnection(QObject *parent, SimNode * start, SimNode * end, int ID)
{
	//store refs to the end nodes and a ID ref to the spring in the node
	conNodes[0] = start;
	conNodes[0]->connectIDs.append(ID);
	conNodes[1] = end;
	conNodes[1]->connectIDs.append(ID);
	extension = 0;
	lastExtension = 0;
}

SimConnection::~SimConnection()
{

}

void SimConnection::CalcSpringForces()
{
	//increasing k value in compression to simulate internal pressure //-> SCRAPPED
	//if (vect.length() < baseLength) 
	//{
	//	scaledK = k / (baseLength / vect.length());
	//}
	//else 
	//{
	//	scaledK = k;
	//}
	//calculate tension force in the spring and approximation of velocity
	lastExtension = extension;
	vect = conNodes[0]->pos - conNodes[1]->pos;
	extension = (vect.length() - baseLength);
	vel = extension - lastExtension;
	//apply force to each node
	springForce = vect.normalized() * extension * scaledK; //F = -kx
	dampingForce = vect.normalized() * vel * c; //F = -c(dx/dy)
	conNodes[0]->forces.append(-(springForce + dampingForce));
	conNodes[1]->forces.append(springForce + dampingForce);
}

void SimConnection::HandleCollision(QList<SimNode*> possNodes, QList<SimConnection*> springs)
{
	for (int i = 0; i < 2; i++)
	{
		//for each spring adjacent to this one
		for each (int n in conNodes[i]->connectIDs)
		{
			if (springs[n] != this)
			{
				//calculate angle between the springs
				float dot = vect.x()*springs[n]->vect.x() + vect.y()*springs[n]->vect.y();
				float det = vect.x()*springs[n]->vect.y() - vect.y()*springs[n]->vect.x();
				float angle = atan2(det, dot);
				SimNode * moveNode;
				//if the angle is less than 90 degs apply spring force
				if (abs(angle) < PI/2)
				{
					if (springs[n]->conNodes[0] != conNodes[i]) moveNode = springs[n]->conNodes[0];
					QVector2D moveSpring = moveNode->pos - conNodes[i]->pos;
					//find perpendicular vector
				}
			}
		}
	}

	// ======== ATTEMPT TO PREVENT INVERSION- FOR REFERENCE ======== //
	//QVector2D distance0;
	//QVector2D distance1;
	//for each (SimNode * node in possNodes)
	//{
	//	if (node == conNodes[0] || node == conNodes[1]) continue;
	//	//check if node is closer to end node than length of spring
	//	distance0 = node->pos - conNodes[0]->pos;
	//	if (abs(distance0.length()) < vect.length())
	//	{
	//		//check if sum of node distance from end nodes is 
	//		//less than spring length + size of node
	//		distance1 = node->pos - conNodes[1]->pos;
	//		if (abs(distance0.length()) + abs(distance1.length()) - vect.length() < 10)
	//		{
	//			//for each (int n in conNodes[0]->connectIDs)
	//			//{
	//			//	if (springs[n]->conNodes[0] == node || springs[n]->conNodes[1] == node)
	//			//	{
	//			//		springs[n]->minLength = vect.length() / 2 + 10;
	//			//	}
	//			//}
	//			//maxLength = vect.length();
	//			//node->Collide(vect);
	//			float dot = vect.x()*node->vel.x() + vect.y()*node->vel.y();
	//			float det = vect.x()*node->vel.y() - vect.y()*node->vel.x();
	//			float angle = abs(atan2(det, dot));
	//			if (angle > PI/2) angle = PI - angle;
	//			QVector2D component = node->vel * sin(angle);
	//			if (node->dragging == false)
	//			{
	//				node->vel -= 2 * component;
	//				node->vel *= 0.5;
	//				node->debugForce = -component;
	//			}
	//			component = conNodes[0]->vel * sin(angle);
	//			conNodes[0]->vel -= 2 * component;
	//			component = conNodes[1]->vel * sin(angle);
	//			conNodes[1]->vel -= 2 * component;
	//			
	//		}
	//	}
	//}
}

//OBSOLETE FUNCTION TO KEEP SPRING LENGTH TO MINIMUM
void SimConnection::HandleMinLength()
{
	if (vect.length() < minLength)
	{
		if(conNodes[0]->fixed || conNodes[0]->dragging) conNodes[1]->pos -= vect.normalized() * (minLength - vect.length());
		else if (conNodes[1]->fixed || conNodes[1]->dragging) conNodes[0]->pos -= vect.normalized() * (minLength - vect.length());
		else
		{
			conNodes[0]->pos += vect.normalized() * (minLength - vect.length()) / 2;
			conNodes[1]->pos -= vect.normalized() * (minLength - vect.length()) / 2;
		}
	}
	//if (maxLength != 0 && vect.length() > maxLength)
	//{
	//	conNodes[0]->pos += vect.normalized() * (vect.length() - maxLength) / 2;
	//	conNodes[1]->pos -= vect.normalized() * (vect.length() - maxLength) / 2;
	//}
	//maxLength = 0;
	//minLength = 0;
}
