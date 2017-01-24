#include "simnode.h"

SimNode::SimNode(QObject *parent, QVector2D startPos)
	: QObject(parent)
{
	pos = startPos;
	lastPos = startPos;
}

SimNode::~SimNode()
{

}


//Finds sum of all forces acting on the node
//handles bouncing etc
void SimNode::CalcForces()
{
	if (dragging == false)
	{
		acc = QVector2D(0, 1);
		//calculate forces
		for each (QVector2D f in forces)
		{
			acc += (f / mass);
		}
		//calculate gravity acc
		vel += acc;
		vel *= resistance; //replace with acceleration?

		float newY = pos.y() + vel.y();
		float newX = pos.x() + vel.x();
		//bouncing off walls
		if (newY > 490 || newY < 10)
		{
			//handle rounding errors
			if (vel.length() < 2) bounceFactor = 0;
			else if (vel.length() < 5) bounceFactor = 0.2;
			else if (vel.length() < 9) bounceFactor = 0.3;

			vel = QVector2D(vel.x(), vel.y() * -bounceFactor);
		}
		if (newX > 790 || newX < 10)
		{
			vel = QVector2D(vel.x() * -bounceFactor, vel.y());
		}
		else
		{
			//resistance = 0.98;
			bounceFactor = 0.5;
		}
	}
}

//Updates the position of the node according to its velocity
void SimNode::UpdatePos()
{
	if (dragging == false)
	{
		pos += vel;
		vel = pos - lastPos;
		lastPos = pos;
	}
}

//moves position of node for initialisation or dragging
void SimNode::MoveNode(QVector2D newPos)
{
	pos = newPos;
	vel = pos-lastPos;
	lastPos = pos;
}

//obsolete function for colliding with lines
void SimNode::Collide(QVector2D planeVect)
{
	float dot = planeVect.x()*vel.x() + planeVect.y()*vel.y();
	float det = planeVect.x()*vel.y() - planeVect.y()*vel.x();
	float angle = atan2(det, dot);
	QVector2D component = vel * sin(angle);
	vel -= 2 * component;
}