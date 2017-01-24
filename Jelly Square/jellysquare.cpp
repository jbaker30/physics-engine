#include "jellysquare.h"

JellySquare::JellySquare(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//initialises adjustable constants
	ui.graphicsView->ChangeMass(ui.massSlider->value());
	ui.graphicsView->ChangeSpring(ui.springSlider->value());
	ui.graphicsView->ChangeDamper(ui.dampingSlider->value());
	ui.graphicsView->ChangeResistance(ui.resistanceSlider->value());
	ui.graphicsView->ChangePressure(ui.intSlider->value());

	//setup timestep timer
	QTimer * timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(Update()));
	timer->start(20);
}

JellySquare::~JellySquare()
{

}

//called every 20ms
void JellySquare::Update()
{
	ui.graphicsView->CUpdate();
}