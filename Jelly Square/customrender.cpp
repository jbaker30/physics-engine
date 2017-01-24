#include "customrender.h"

CustomRender::CustomRender(QWidget *parent)
	: QGraphicsView(parent)
{
	nodeDragging = false;
	scene = new QGraphicsScene;
	QSize viewSize = size();
	scene->setSceneRect(10, 10, viewSize.width(), viewSize.height());
	setScene(scene);

	//initialise pens
	fixPen.setWidth(2);
	fixPen.setColor(Qt::red);
	forcePen2.setWidth(2);
	forcePen2.setColor(Qt::yellow);
	forcePen.setWidth(5);
	forcePen.setColor(Qt::blue);
	mainPen.setWidth(2);
	mainPen.setColor(Qt::black);

	InitSimulation();
}

CustomRender::~CustomRender()
{

}

//==============================LOGIC==============================//

//main update function, called from jellysquare.cpp every 20ms
void CustomRender::CUpdate() 
{
	scene->clear();
	//move any dragged nodes to the mouse position
	if (nodeDragging)
	{
		QVector2D mousePos = (QVector2D)mapFromGlobal(QCursor::pos());
		draggedNode->MoveNode(mousePos);

		//prevent offscreen dragging
		if (mousePos.x() < 10.0f) 
			draggedNode->MoveNode(QVector2D(10.f, mousePos.y()));
		else if (mousePos.x() > 790.f) 
			draggedNode->MoveNode(QVector2D(790.f, mousePos.y()));
		if (mousePos.y() < 10.f) 
			draggedNode->MoveNode(QVector2D(mousePos.x(), 10.f));
		else if (mousePos.y() > 490.f) 
			draggedNode->MoveNode(QVector2D(mousePos.x(), 490.f));
	}
	//check extension of each spring and apply appropriate forces
	for each (SimConnection* spring in springs)
	{
		spring->CalcSpringForces();
	}
	//apply outward pressure to each element
	for each (SimElement* element in elements)
	{
		element->CalcInternalForces();
	}
	//calculate position of each node according to forces
	//applied to it
	for each (SimNode* node in nodes)
	{
		if (node->fixed) DrawNode(node, fixPen);
		else
		{
			node->CalcForces();
			node->UpdatePos();
			DrawNode(node, mainPen);
			
		}
		node->forces.clear();
	}
	//draw each spring
	for each (SimConnection* spring in springs)
	{
		DrawConnection(spring);
	}
	//resets simulation if nodes shoot offscreen
	//usually result of unlikely 
	for each (SimNode* node in nodes)
	{
		if (isnan(node->pos.x()) || isnan(node->pos.y()))
		{
			InitSimulation();
			break;
		}
	}
}

//check if a mouse click is on a node and if yes return true
//saves node to drag into draggednode variable
bool CustomRender::CheckCollision(QVector2D mousePos)
{
	int diff;
	bool returnVal = false;
	//for each node
	for each (SimNode* node in nodes)
	{
		diff = mousePos.distanceToPoint(node->pos);
		if (diff < 10)
		{
			draggedNode = node;
			draggedNode->dragging = true;
			returnVal = true;
			break;
		}
	}
	return returnVal;
}

void CustomRender::InitSimulation()
{
	//initialise node positions
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			nodes[x][y] = new SimNode(this, QVector2D((x + 1) * 100, (y + 1) * 100));
		}
	}
	//initialise connections in grid
	int springCounter = 0;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			springs[springCounter] = new SimConnection(this, nodes[x][y], nodes[x][y + 1], springCounter);
			springCounter++;
		}
	}
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			springs[springCounter] = new SimConnection(this, nodes[x][y], nodes[x + 1][y], springCounter);
			springCounter++;
		}
	}
	//save individual squares
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			elements[y * 3 + x] = new SimElement(this, nodes[x][y], nodes[x + 1][y], nodes[x + 1][y + 1], nodes[x][y + 1]);
			elements[y * 3 + x]->conSprings[0] = springs[y * 3 + x + y];
			elements[y * 3 + x]->conSprings[1] = springs[y * 3 + x + 12];
			elements[y * 3 + x]->conSprings[2] = springs[y * 3 + x + y + 1];
			elements[y * 3 + x]->conSprings[3] = springs[y * 3 + x + 15];
		}
	}

	//reset sliders
	emit ResetMass(10);
	emit ResetSpring(20);
	emit ResetDamper(5);
	emit ResetPressure(20);
	emit ResetResistance(98);
	ChangeMass(10);
	ChangeSpring(20);
	ChangeDamper(5);
	ChangePressure(20);
	ChangeResistance(98);
}

//==============================DRAWING FUNCTIONS==============================//

//function to draw a particular saved node with the given pen
void CustomRender::DrawNode(SimNode * n, QPen pen)
{
	scene->addEllipse(n->pos.x(), n->pos.y(), 20, 20, pen);
}

//function to draw a particular saved spring with the standard pen
void CustomRender::DrawConnection(SimConnection * c)
{
	scene->addLine(c->conNodes[0]->pos.x() + 10, c->conNodes[0]->pos.y() + 10,
		c->conNodes[1]->pos.x() + 10, c->conNodes[1]->pos.y() + 10, mainPen);
}

//FOR DEBUG PURPOSES- draw force vector acting on a particular node with a given pen
void CustomRender::DrawForce(QVector2D force, SimNode* node, QPen pen)
{
	scene->addLine(node->pos.x() + 10, node->pos.y() + 10,
		node->pos.x() + force.x() + 10, node->pos.y() + force.y() + 10, pen);
}

//==============================SLOTS FOR MOUSE CLICK HANDLING==============================//

void CustomRender::mousePressEvent(QMouseEvent * e)
{
	//handle dragging and fixing points
	QPoint pos = e->pos();
	QVector2D posVect = (QVector2D)pos;
	if (CheckCollision(posVect))
	{
		//fix or unfix nodes with right click
		if (e->button() == Qt::MouseButton::RightButton)
		{
			if (draggedNode->fixed == true)
				draggedNode->fixed = false;
			else draggedNode->fixed = true;
			draggedNode->dragging = false;
		}
		//drag with left click
		else
		{
			nodeDragging = true;
			draggedNode->vel = QVector2D(0, 0);
		}
	}
}

void CustomRender::mouseReleaseEvent(QMouseEvent * e)
{
	//stop dragging
	if (nodeDragging)
	{
		draggedNode->dragging = false;
		nodeDragging = false;
		draggedNode = NULL;
	}

}

//==============================SLOTS FOR UI INPUT==============================//
void CustomRender::ChangeMass(int value)
{
	for each (SimNode* node in nodes)
	{
		node->mass = ((float)value) / 100;
	}
}

void CustomRender::ChangeSpring(int value)
{
	for each (SimConnection* spring in springs)
	{
		spring->k = ((float)value) / 1000;
		spring->scaledK = spring->k;
	}
}

void CustomRender::ChangeDamper(int value)
{
	for each (SimConnection* spring in springs)
	{
		spring->c = ((float)value) / 1000;
	}
}

void CustomRender::ChangeResistance(int value)
{
	for each (SimNode* node in nodes)
	{
		node->resistance = ((float)value) / 100;
	}
}

void CustomRender::ChangePressure(int value)
{
	for each (SimElement* element in elements)
	{
		element->intForce = ((float)value) / 1000;
	}
}

void CustomRender::ResetSimulation()
{
	InitSimulation();
}
