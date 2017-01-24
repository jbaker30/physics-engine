#include "simelement.h"
#define PI 3.14159265359


//overloaded constructor to set up element made up of specified nodes
SimElement::SimElement(QObject *parent, SimNode* n1, SimNode* n2, SimNode* n3, SimNode* n4)
	: QObject(parent)
{
	conNodes.append(n1);
	conNodes.append(n2);
	conNodes.append(n3);
	conNodes.append(n4);
}

SimElement::~SimElement()
{

}

//calculates internal pressure of the element
void SimElement::CalcInternalForces()
{
	QVector2D vectSum;
	QVector2D vectCentre;
	QVector2D vect;
	float extension; //distance of each node from centre of element
	
	//find sum of all the element's nodes' positions
	for each (SimNode* node in conNodes)
	{
		vectSum += node->pos;
	}
	//averages sum to find the centre of mass for the element
	vectCentre = QVector2D(vectSum.x() / 4, vectSum.y() / 4);
	//applies force to each node outwards from the centre
	for each (SimNode* node in conNodes)
	{
		if (!node->fixed)
		{
			vect = node->pos - vectCentre;
			extension = vect.length() - baseSize;
			node->forces.append(-vect.normalized() * intForce * extension);
		}
	}
}

// FOR REFERENCE --- ATTEMPT AT HANDLING INVERSION BY FINDING ANGLE BETWEEN SPRINGS OF THE ELEMENT
//void SimElement::HandleCollision()
//{
//	for (int i = 0; i < 4; i++)
//	{
//		int i2 = (i + 1) % 4;
//		float dot = conSprings[i]->vect.x()*conSprings[i2]->vect.x() + conSprings[i]->vect.y()*conSprings[i2]->vect.y();
//		float det = conSprings[i]->vect.x()*conSprings[i2]->vect.y() - conSprings[i]->vect.y()*conSprings[i2]->vect.x();
//		float angle = atan2(det, dot);
//		if (abs(angle) < PI / 2)
//		{
//			SimNode* moveNode1;
//			SimNode* moveNode2;
//			if (conSprings[i]->conNodes[0] == conSprings[i2]->conNodes[0])
//			{
//				moveNode1 = conSprings[i]->conNodes[1];
//				moveNode2 = conSprings[i2]->conNodes[1];
//			}
//			else if (conSprings[i]->conNodes[1] == conSprings[i2]->conNodes[0])
//			{
//				moveNode1 = conSprings[i]->conNodes[0];
//				moveNode2 = conSprings[i2]->conNodes[1];
//			}
//			else if (conSprings[i]->conNodes[0] == conSprings[i2]->conNodes[1])
//			{
//				moveNode1 = conSprings[i]->conNodes[1];
//				moveNode2 = conSprings[i2]->conNodes[0];
//			}
//			else if (conSprings[i]->conNodes[1] == conSprings[i2]->conNodes[1])
//			{
//				moveNode1 = conSprings[i]->conNodes[0];
//				moveNode2 = conSprings[i2]->conNodes[0];
//			}
//			qInfo("dhfhsdk");
//		}
//	}
//}