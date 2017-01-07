#include "simnode.h"

SimNode::SimNode(QObject *parent)
	: QObject(parent)
{
	pos = QVector2D(0, 0);
	bounceFactor = 0.8;
}

SimNode::~SimNode()
{

}

void SimNode::UpdatePos()
{
	//calculate gravity acc
	vel = QVector2D(vel.x(), vel.y() + 1 );
	//vel *= 0.95;
	float newY = pos.y() + vel.y();
	float newX = pos.x() + vel.x();
	//bouncing off walls
	if (newY > 490 || newY < 10)
	{
		//handle rounding errors
		if (vel.length() < 2) bounceFactor = 0;
		else if (vel.length() < 5) bounceFactor = 0.3;
		else if (vel.length() < 9) bounceFactor = 0.5;

		vel = QVector2D(vel.x() * bounceFactor, vel.y() * -bounceFactor);
	}
	if (newX > 790 || newX < 10)
	{
		vel = QVector2D(vel.x() * -bounceFactor, vel.y());
	}
	else
	{
		bounceFactor = 0.8;
	}
	pos += vel;
	vel = pos-lastPos;
	lastPos = pos;
}

void SimNode::MoveNode(QVector2D newPos)
{
	pos = newPos;
	vel = pos-lastPos;
	lastPos = pos;
}
